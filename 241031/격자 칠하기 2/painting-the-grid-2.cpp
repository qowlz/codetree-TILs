#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

#define MAX_NUM 1000000

int n;
vector<vector<int>> arr;
vector<vector<bool>> visit;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int getTotal(int sy, int sx, int d)
{
    visit[sy][sx] = true;

    int total = 0;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while(!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        total++;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visit[ny][nx] || abs(arr[y][x] - arr[ny][nx]) > d) continue;

            visit[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    return total;
}

bool isPossible(int mid)
{
    int best = 0;
    visit.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            best = max(best, getTotal(i, j, mid));
    
    return best >= (n * n) / 2;
}

int main() {
    cin >> n;

    arr.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int left = 0, right = MAX_NUM;
    int ans = right;
    while(left <= right)
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