#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int getBlockSize(vector<vector<int>>& arr, int y, int x)
{
    vector<pair<int, int>> check;
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    visit[y][x] = true;
    check.push_back(make_pair(y, x));
    
    int idx = 0;
    while (idx < check.size())
    {
        auto p = check[idx++];
        for (int i = 0; i < 4; i++)
        {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (visit[ny][nx] || !arr[p.first][p.second] || arr[p.first][p.second] != arr[ny][nx]) continue;
            
            visit[ny][nx] = true;
            check.push_back(make_pair(ny, nx));
        }
    }

    if (check.size() >= 4)
    {
        for (int i = 0; i < check.size(); i++) 
            arr[check[i].first][check[i].second] = 0;
    }

    return check.size();
}

int main() 
{
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            auto size = getBlockSize(arr, i, j);
            ans2 = max(ans2, size);
            if (size >= 4) ans1++;
        }
    }

    cout << ans1 << ' ' << ans2;


    return 0;
}