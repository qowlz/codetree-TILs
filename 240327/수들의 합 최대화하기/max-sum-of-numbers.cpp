#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<vector<int>> board;
vector<bool> col;

int solve(int row, int acc)
{
    if (row >= N) return acc;
    
    int ret = acc;
    for (int i = 0; i < N; i++)
    {
        if (col[i]) continue;

        col[i] = true;
        ret = max(ret, solve(row + 1, acc + board[row][i]));
        col[i] = false;
    }

    return ret;
}


int main() {
    cin >> N;

    board.assign(N, vector<int>(N, 0));
    col.assign(N, false);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << solve(0, 0);

    return 0;
}