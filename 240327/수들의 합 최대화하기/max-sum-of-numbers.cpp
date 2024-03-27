#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<vector<int>> board;
vector<pair<int, int>> pick;
vector<bool> row;
vector<bool> col;

int solve()
{
    if (pick.size() >= N)
    {
        int sum = 0;
        for (int i = 0; i < pick.size(); i++)
            sum += board[pick[i].first][pick[i].second];
        
        return sum;
    }

    int ret = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (row[i] || col[j]) continue;

            row[i] = true; col[j] = true;
            pick.push_back(make_pair(i, j));
            ret = max(ret, solve());
            row[i] = false; col[j] = false;
            pick.pop_back();
        }
    }

    return ret;
}


int main() {
    cin >> N;

    board.assign(N, vector<int>(N, 0));
    row.assign(N, false);
    col.assign(N, false);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << solve();

    return 0;
}