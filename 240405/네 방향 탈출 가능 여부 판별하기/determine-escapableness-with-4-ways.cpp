#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visit;

bool inRange(int x, int y)
{
    return !(y < 0 || y >= N || x < 0 || x >= M);
}

int main() {
    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));
    visit.assign(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();

        if (pos.first == M - 1 && pos.second == N - 1)
        {
            cout << "1";
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if (!inRange(nx, ny) || !board[ny][nx] || visit[ny][nx]) continue;

            visit[ny][nx] = true;
            q.push(make_pair(nx, ny));
        }
    }

    cout << "0";

    return 0;
}