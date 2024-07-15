#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> red(2 * n + 1, 0);
    vector<int> blue(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> red[i] >> blue[i];
    }

    // dp[i][j][k]: i번째 시행일 때, 빨강을 j개 선택하고 파랑을 k개 선택했을 때 나올 수 있는 최대합    
    vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 0; j <= min(i, n); j++)
        {
            for (int k = 0; k <= min(i, n); k++)
            {
                if (j + k > i || j + k == 0) continue;

                if (j > 0) // 빨간색 카드를 고른 경우
                    dp[i][j][k] = red[i] + dp[i - 1][j - 1][k];
                
                if (k > 0) // 파란색 카드를 고른 경우
                    dp[i][j][k] = max(dp[i][j][k], blue[i] + dp[i - 1][j][k - 1]);
            
                // cout << "dp[" << i << "][" << j << "][" << k << "]: " << dp[i][j][k] << endl; 
            }
        }
    }

    cout << dp[2 * n][n][n];

    return 0;
}