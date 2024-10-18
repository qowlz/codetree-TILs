#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using IntPair = pair<int, int>;

#define MAX_N 100000
#define INF (int)1e8

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> g[MAX_N + 1];
    while (m--)
    {
        int i, j, d;
        cin >> i >> j >> d;

        g[j].push_back(make_pair(i, d));
    }

    vector<int> dist(n + 1, INF);
    dist[n] = 0;

    priority_queue<IntPair, vector<IntPair>, greater<IntPair>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(dist[i], i));
    
    while (!pq.empty())
    {
        int total, u;
        tie(total, u) = pq.top();
        pq.pop();

        if (total != dist[u]) continue;

        for (int i = 0; i < g[u].size(); i++)
        {
            int d, v;
            tie(v, d) = g[u][i];

            int nd = total + d;
            if (nd >= dist[v]) continue;
            
            dist[v] = nd;
            pq.push(make_pair(dist[v], v));
        }
    }

    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (dist[i] == INF) continue;
        ans = max(ans, dist[i]);
    }
    
    cout << ans;

    return 0;
}