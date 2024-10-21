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

    int ans = 0;    
    for (int s = 1; s <= n; s++)
    {
        if (s == a || s == b || s == c) continue;

        auto dist = dijkstra(s);
        int closest = min(dist[a], dist[b]);
        closest = min(closest, dist[c]);
        ans = max(ans, closest);
    }

    cout << ans;

    return 0;
}