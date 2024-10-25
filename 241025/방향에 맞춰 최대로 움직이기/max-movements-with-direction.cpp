#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, r, c, ans = 0, cnt = 0;
vector<vector<int>> board;
vector<vector<int>> dir;
vector<vector<bool>> visit;

int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};
int dx[] = {0, -1, -1, 0, 1, 1,  1,  0, -1};

bool isOutOfRange(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

void solve(int curX, int curY)
{
    // cout << "start: " << curX << ", " << curY << " value: " << board[curX][curY] << endl;
    // cout << "cnt: " << cnt << endl;

    // 이동가능한 후보들 선택
    vector<pair<int, int>> c;
    int nx = curX + dx[dir[curX][curY]], ny = curY + dy[dir[curX][curY]];
    // cout << "\tcc: " << nx << ", " << ny << " dir: " << dir[curX][curY] << endl;
    while (!isOutOfRange(nx, ny))
    {
        // cout << "\tcheck: " << nx << ", " << ny << " value: " << board[nx][ny] << endl;
        if (!visit[nx][ny] && board[nx][ny] > board[curX][curY]) 
            c.push_back({nx, ny});

        nx += dx[dir[curX][curY]];
        ny += dy[dir[curX][curY]];
    }

    if (c.empty())
    {
        ans = max(ans, cnt);
        return;
    }

    int x, y;
    for (int i = 0; i < c.size(); i++)
    {
        tie(x, y) = c[i];

        visit[x][y] = true;
        cnt++;

        // cout << "\tcandidate: " << x << ", " << y << endl;
        solve(x, y);

        visit[x][y] = false;
        cnt--;
    }
}

int main() {
    cin >> n;

    board.assign(n, vector<int>(n, 0));
    dir.assign(n, vector<int>(n, 0));
    visit.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dir[i][j];
    
    cin >> r >> c;

    visit[r - 1][c - 1] = true;
    solve(r - 1, c - 1);

    cout << ans;
            
    return 0;
}