#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 100000
#define INF 1e9

int n, m;
vector<pair<int, int>> g[MAX_N + 1];

vector<int> dijkstra(int s)
{
    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(dist[i], i));
        

    while(!pq.empty())
    {
        int d, u;
        tie(d, u) = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (int i = 0; i < g[u].size(); i++)
        {
            int v, w;
            tie(v, w) = g[u][i];
            if (d + w >= dist[v]) continue;

            dist[v] = d + w;
            pq.push(make_pair(dist[v], v));
        }
    }

    return dist;
}

int main() {
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b >> c;

    // 그래프 구성
    while (m--)
    {
        int s, e, w;
        cin >> s >> e >> w;
        g[s].push_back(make_pair(e, w));
        g[e].push_back(make_pair(s, w));
    }

    vector<int> candidates(n + 1, INF);
    int arr[3] = {a, b, c};   
    for (int i = 0; i < 3; i++)
    {
        auto dist = dijkstra(arr[i]);
        for (int j = 1; j < n; j++)
            candidates[j] = min(candidates[j], dist[j]);
    }

    int ans = 0;
    for (const auto& c : candidates)
    {
        if (c != INF) ans = max(ans, c);
    }

    cout << ans;

    return 0;
}