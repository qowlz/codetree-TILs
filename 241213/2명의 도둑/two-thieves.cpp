#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, c;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int selectedValue;
int totalValue = 0;

int getMaxValue(vector<pair<int, int>>& stuffs, int si, int value, int totalWeight)
{
    int best = value;
    for (int i = si; i < stuffs.size(); i++)
    {
        int y, x;
        tie(y, x) = stuffs[i];
        if (totalWeight + arr[y][x] > c) continue;
        
        int newValue = value + arr[y][x] * arr[y][x];
        best = max(best, getMaxValue(stuffs, i + 1, newValue, totalWeight + arr[y][x]));
    }

    return best;
}

int solve(int sy, int sx, int selectCnt)
{
    if (selectCnt == 2)
    {
        // cout << "totalValue: " << totalValue << endl;
        return totalValue;
    }

    int best = 0;
    for (int i = sy; i < n; i++)
    {
        for (int j = sx; j < n; j++)
        {
            if (visited[i][j]) continue;

            vector<pair<int, int>> stuffs;
            for (int k = 0; k < m; k++)
            {
                if (j + k >= n) break;

                visited[i][j + k] = true;
                stuffs.push_back({i, j + k});
            }

            int values = getMaxValue(stuffs, 0, 0, 0);

            // cout << "i: " << i << ", j: " << j << endl;
            // cout << "\tselectCnt: " << selectCnt << endl;
            // cout << "\tvalues: " << values << endl;

            totalValue += values;
            
            int sy = j + m >= n ? i + 1 : i;
            int sx = j + m >= n ? 0 : j;
            best = max(best, solve(sy, sx, selectCnt + 1));

            totalValue -= values;

            // visited 원복
            for (int k = 0; k < m; k++)
            {
                if (j + k >= n) break;

                visited[i][j + k] = false;
            }
        }
    }

    return best;
}

int main() {
    cin >> n >> m >> c;

    arr.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    visited.assign(n, vector<bool>(n, false));
    cout << solve(0, 0, 0);
    
    return 0;
}