#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;
using IntTuple = tuple<int, int, int>;

#define MAX_N 1000
#define INF 1000000000000

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    // 그래프 구성
    int line = 0;
    vector<IntTuple> g[MAX_N + 1];
    for (int i = 0; i < n; i++)
    {
        int f, c;
        cin >> f >> c;

        line++;
        int from = 0;
        while (c--)
        {
            int to;
            cin >> to;

            if (from) g[from].push_back(make_tuple(to, f, line));
            
            from = to;
        }
    }

    // 거리 비용 초기화
    vector<unsigned long long> dist(MAX_N + 1, INF);
    dist[a] = 0;

    // 우선순위 큐 초기화
    priority_queue<IntTuple, vector<IntTuple>, greater<IntTuple>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_tuple(dist[i], i, 0));
    
    vector<int> path(MAX_N + 1, 0);
    while (!pq.empty())
    {
        int c, v, l;
        tie(c, v, l) = pq.top();
        pq.pop();

        if (c != dist[v]) continue;

        for (int i = 0; i < g[v].size(); i++)
        {
            int to, fee, to_l;
            tie(to, fee, to_l) = g[v][i];

            unsigned long long nc = c + (l == to_l ? 0 : fee);
            if (nc >= dist[to]) continue;

            dist[to] = nc;
            path[to] = v;
            pq.push(make_tuple(dist[to], to, to_l));
        }
    }
    
    // 정답 출력
    if (dist[b] == INF)
    {
        cout << "-1 -1";
    }
    else
    {
        // 시간 계산
        int t = 0;
        int s = b;
        while (s != a)
        {
            s = path[s];
            t += 1;
        }


        cout << dist[b] << ' ' << t;
    }

    
    return 0;
}