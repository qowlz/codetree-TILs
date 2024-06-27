#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;

    vector<int> coin(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    vector<int> dp(M + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        int maximum = 0;
        for (int j = 0; j < N; j++)
        {
            if (i >= coin[j] && dp[i - coin[j]] > 0)
                maximum = max(maximum, dp[coin[j]] + dp[i - coin[j]]);
        }
        dp[i] = maximum;
    }

    if (dp[M] == 0)
        cout << "-1";
    else
        cout << dp[M];

    return 0;
}