#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<bool>> picked;
vector<pair<int, int>> pick;
vector<vector<int>> arr;
int N, K, U, D;

bool isOutRange(int y, int x)
{
    return y < 0 || y >= N || x < 0 || x >= N;
}

int bfs()
{
    int ret = 0;
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    for (int i = 0; i < pick.size(); i++)
    {
        if (visit[pick[i].first][pick[i].second]) continue;

        // cout << "pick: " << pick[i].first << ", " << pick[i].second << endl;

        queue<pair<int, int>> q;
        q.push(pick[i]);
        visit[pick[i].first][pick[i].second] = true;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            ret++;

            // cout << '\t' << "pop: " << p.first << ", " << p.second << endl;
            
            for (int j = 0; j < 4; j++)
            {
                int ny = p.first + dy[j];
                int nx = p.second + dx[j];
                if (isOutRange(ny, nx) || visit[ny][nx]) continue;

                auto diff = abs(arr[p.first][p.second] - arr[ny][nx]);
                if (diff < U || diff > D) continue;

                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }

    return ret;
}

int solve()
{
    if (pick.size() >= K) return bfs();

    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (picked[i][j]) continue;

            pick.push_back(make_pair(i, j));
            picked[i][j] = true;

            ret = max(ret, solve());

            pick.pop_back();
            picked[i][j] = false;
        }
    }

    return ret;
}


int main() {
    cin >> N >> K >> U >> D;

    arr.assign(N, vector<int>(N, 0));
    picked.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    cout << solve();

    return 0;
}