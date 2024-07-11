#include <iostream>
#include <vector>
using namespace std;

#define ACT_MAX 3

int main() {
    int n = 0;
    cin >> n;

    vector<int> coins(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(ACT_MAX + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= ACT_MAX; j++)
        {
            // 1계단을 오르는 경우
            if (j > 0 && i >= j)
                dp[i][j] = max(dp[i][j], coins[i] + dp[i - 1][j - 1]);

            // 2계단을 오르는 경우
            if(i >= 2)
                dp[i][j] = max(dp[i][j], coins[i] + dp[i - 2][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i <= 3; i++)
    {
        answer = max(answer, dp[n][i]);
    }

    cout << answer;


    return 0;
}