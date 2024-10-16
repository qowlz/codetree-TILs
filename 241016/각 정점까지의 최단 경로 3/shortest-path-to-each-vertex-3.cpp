#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using P = pair<int, int>;

const int INF = 1001;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        
        arr[s][e] = w;
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(i == 1 ? 0 : INF, i));
    
    vector<int> ans(n + 1, INF);
    while(!pq.empty())
    {
        int d, s;
        tie(d, s) = pq.top();
        pq.pop();

        for (int e = 1; e <= n; e++)
        {
            if (e == s) continue;
            if (arr[s][e] == INF) continue;

            if (d + arr[s][e] < ans[e])
            {
                ans[e] = d + arr[s][e];
                pq.push(make_pair(ans[e], e));
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << ans[i] << '\n';

    return 0;
}