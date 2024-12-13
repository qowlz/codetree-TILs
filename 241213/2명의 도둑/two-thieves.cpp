#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int totalValue = 0;

int solve(int sy, int sx, int selectCnt)
{
    if (selectCnt == 2)
        return totalValue;

    int best = 0;
    for (int i = sy; i < n; i++)
    {
        for (int j = sx; j < n; j++)
        {
            if (visited[i][j]) continue;

            int totalWeight = 0;
            int values = 0;
            for (int k = 0; k < m; k++)
            {
                if (j + k >= n) break;

                visited[i][j + k] = true;

                totalWeight += arr[i][j + k];
                if (totalWeight <= c)
                    values += arr[i][j + k] * arr[i][j + k];
            }

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