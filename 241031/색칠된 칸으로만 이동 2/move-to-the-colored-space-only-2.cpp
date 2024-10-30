#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int colored_total = 0;
vector<vector<int>> arr;
vector<vector<bool>> visit;
vector<vector<int>> colored;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int y, int x, int d)
{
    visit[y][x] = true;

    int cnt = colored[y][x] ? 1 : 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (visit[ny][nx] || abs(arr[y][x] - arr[ny][nx]) > d) continue;

        cnt += dfs(ny, nx, d);
    }

    return cnt;
}


bool isPossible(int mid)
{
    int total = 0;
    visit.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            total = max(total, dfs(i, j, mid));
        }
    }

    return total >= colored_total;
}

int main() {
    cin >> m >> n;

    arr.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    colored.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> colored[i][j];
            if(colored[i][j]) colored_total++;
        }
    }

    int left = 0, right = 1e9;
    int ans = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;


    return 0;
}