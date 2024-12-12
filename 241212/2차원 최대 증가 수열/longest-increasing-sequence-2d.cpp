#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> dp;

int getMax(int maxY, int maxX, int x)
{
    int best = 0;
    for (int i = 0; i <= maxY; i++)
    {
        for (int j = 0; j <= maxX; j++)
        {
            if (arr[i][j] >= x) continue;

            best = max(best, dp[i][j]);
        }
    }

    return best;
}

int main() {
    cin >> n >> m;

    arr.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    dp.assign(n, vector<int>(m, 0));
    dp[0][0] = 1;

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int best = getMax(i - 1, j - 1, arr[i][j]);
            dp[i][j] = best > 0 ? best + 1 : 0;
            ans = max(ans, dp[i][j]);

            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
            // cout << "\tbest: " << best << endl;
        }
    }
    
    cout << ans;

    return 0;
}