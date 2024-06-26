#include <iostream>
#include <vector>
using namespace std;

#define MOD 10007

int N;

int main() {
    cin >> N;

    int nums[] = {1, 2, 5};
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i - nums[j] >= 0)
                dp[i] += dp[i - nums[j]] % MOD;
        }
    }

    cout << dp[N] % MOD << endl;


    // dp[1] = 1 + 0
    // dp[2] = 1 + 1, 2 + 0
    // dp[3] = 1 + 1 + 1, 1 + 2, 2 + 1
    // dp[4] = 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 

    // (dp[2] - (dp[1] * dp[2 - 1])) * dp[n - 2]
    // 1
    // (dp[5])

    // dp[1] * dp[n - 1], dp[n - 2], dp[n - 5]
    // 5 + 3 + 1
    
    

    return 0;
}