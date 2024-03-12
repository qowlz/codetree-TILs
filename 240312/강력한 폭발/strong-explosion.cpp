#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> points;

bool inRange(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < N;
}

vector<pair<int, int>> explosion(vector<vector<bool>>& board, int y, int x, int type)
{
    vector<int> dy;
    vector<int> dx;
    if (type == 1)
    {
        int elemY[] = {-1, -2, 0, 1, 2};
        int elemX[] = {0, 0, 0, 0, 0};
        for (int i = 0; i < 5; i++)
        {
            dy.push_back(elemY[i]);
            dx.push_back(elemX[i]);
        }
    }
    else if (type == 2)
    {
        int elemY[] = {-1, 1, 0, 0, 0};
        int elemX[] = {0, 0, 0, -1, 1};
        for (int i = 0; i < 5; i++)
        {
            dy.push_back(elemY[i]);
            dx.push_back(elemX[i]);
        }
    }
    else if (type == 3)
    {
        int elemY[] = {-1, -1, 0, 1, 1};
        int elemX[] = {-1, 1, 0, -1, 1};
        for (int i = 0; i < 5; i++)
        {
            dy.push_back(elemY[i]);
            dx.push_back(elemX[i]);
        }
    }
    
    vector<pair<int, int>> ret;
    for (int i = 0; i < 5; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inRange(ny, nx) || board[ny][nx]) continue;
        
        board[ny][nx] = true;
        ret.push_back(make_pair(ny, nx));
    }

    return ret;
}

void reset(vector<vector<bool>>& board, const vector<pair<int, int>>& explode)
{
    for (int i = 0; i < explode.size(); i++)
    {
        board[explode[i].first][explode[i].second] = false;
    }
}

int solve(vector<vector<bool>>& board, int idx, int acc)
{
    if (idx >= points.size())
    {
        return acc;
    }

    int ret = 0;
    for (int i = 1; i <= 3; i++)
    {
        auto explode = explosion(board, points[idx].first, points[idx].second, i);
        ret = max(ret, solve(board, idx + 1, acc + explode.size()));
        reset(board, explode);
    }

    return ret;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value = 0;
            cin >> value;
            if (value) points.push_back(make_pair(i, j));
        }
    }

    vector<vector<bool>> board(N, vector<bool>(N, false));
    cout << solve(board, 0, 0);

    return 0;
}