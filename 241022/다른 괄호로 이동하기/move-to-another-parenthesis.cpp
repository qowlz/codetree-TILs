#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, a, b;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

#define INF 900000000
using IntTuple = tuple<int, int, int>;


vector<vector<char>> board;

int solve(int x, int y)
{
    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[x][y] = 0;

    priority_queue<IntTuple, vector<IntTuple>, greater<IntTuple>> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pq.push(make_tuple(dist[i][j], i, j));
    
    while (!pq.empty())
    {
        int d, ux, uy;
        tie(d, ux, uy) = pq.top();
        pq.pop();

        if (d != dist[ux][uy]) continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            int w = board[ux][uy] == board[nx][ny] ? a : b;
            if (d + w >= dist[nx][ny]) continue;

            dist[nx][ny] = d + w;
            pq.push(make_tuple(dist[nx][ny], nx, ny));
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ret = max(ret, dist[i][j]);
    
    return ret;
}


int main() {
    cin >> n >> a >> b;

    board.assign(n, vector<char>(n, '\0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, solve(i, j));
    
    cout << ans;

    return 0;
}