#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using P = pair<int, int>;

#define MAX_N 1000
#define INF 100000001

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr[MAX_N + 1];
    while (m--)
    {
        int s, e, w;
        cin >> s >> e >> w;
        arr[s].push_back(make_pair(e, w));
        arr[e].push_back(make_pair(s, w));
    }

    int a, b;
    cin >> a >> b;

    vector<int> dist(n + 1, INF);
    dist[a] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(dist[i], i));
    
    vector<int> path(n + 1, 0);
    while (!pq.empty())
    {
        int d, u;
        tie(d, u) = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (int i = 0; i < arr[u].size(); ++i)
        {
            int v, w;
            tie(v, w) = arr[u][i];

            int nd = d + w;
            if (nd >= dist[v]) continue;

            dist[v] = nd;
            path[v] = u;
            pq.push(make_pair(dist[v], v));
        }
    }

    cout << dist[b] << '\n';

    vector<int> print(0);
    int current = b;
    while (current)
    {
        print.push_back(current);
        current = path[current];
    }

    for (int i = print.size() - 1; i >= 0; i--)
        cout << print[i] << ' ';

    return 0;
}