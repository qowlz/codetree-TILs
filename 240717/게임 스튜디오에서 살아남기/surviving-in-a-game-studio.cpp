#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

// GG in dp[2][0][0]
// GB in dp[2][0][1]
// GT 

// BG in dp[2][0][0] == dp[1][0][0] + dp[1][0][1]
// BB in dp[2][0][2]
// BT in dp[]

// TG
// TB
// TT

// BGBG
// BBGG

int main() {
    int n;
    cin >> n;

    // dp[i]: i번째 문자까지 고려했을 때, 살아 남을 수 있는 서로 다른 가짓수
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(3, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == 0)
                {
                     // G를 골랐을 경우
                    for (int it = 0; it < 3; it++)
                        dp[i][j][k] = (dp[i][j][k] % MOD + dp[i - 1][j][k + it] % MOD) % MOD;
                    
                    // T를 골랐을 경우
                    if (j > 0)
                    {
                        for (int it = 0; it < 3; it++)
                            dp[i][j][k] = (dp[i][j][k] % MOD + dp[i - 1][j - 1][k + it] % MOD) % MOD;
                    }
                }
                else
                {
                    // B를 골랐을 경우
                    dp[i][j][k] = (dp[i][j][k] % MOD + dp[i - 1][j][k - 1] % MOD) % MOD;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            answer = (answer % MOD + dp[n][i][j] % MOD) % MOD;

    cout << answer;

    return 0;
}