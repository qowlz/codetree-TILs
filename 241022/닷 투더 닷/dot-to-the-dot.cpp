#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <cmath>
using namespace std;
using Tuple = tuple<float, int, int, int>;

#define MAX_N 500
#define INF 600000000


int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<tuple<int, int, int>> g[MAX_N + 1];
    while(m--)
    {
        int i, j, l, c;
        cin >> i >> j >> l >> c;
        g[i].push_back(make_tuple(j, l, c));
        g[j].push_back(make_tuple(i, l, c));
    }

    vector<pair<float, int>> dist(n + 1, make_pair(INF, INF));
    dist[1] = make_pair(0.0f, 0);

    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_tuple(dist[i].first, i, 0, 0));
    
    while (!pq.empty())
    {
        float t;
        int u, a, b;
        tie(t, u, a, b) = pq.top();
        pq.pop();

        if (abs(t - dist[u].first > numeric_limits<float>::epsilon())) continue;

        // cout << "u: " << u << ", b: " << b << endl;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v, l, c;
            tie(v, l, c) = g[u][i];
            // cout << '\t' << "v: " << v << endl;

            int na = a ? min(a, c) : c;
            int nb = b + l;
            float nt = nb + (float)(x / na);
            // cout << '\t' << na << ' ' << nb << ' ' << nt << endl;
            if (nt > dist[v].first) continue;
            if (nt == dist[v].first && nb >= dist[v].second) continue;

            dist[v] = make_pair(nt, nb);
            pq.push(make_tuple(nt, v, na, nb));
        }
    }

    cout << (int)dist[n].first;

    return 0;
}