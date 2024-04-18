#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1] + dp[i - 2] * 3) % MOD;
        for (int j = i - 3; j >= 0; j--)
            dp[i] = (dp[i] + 2 * dp[j]) % MOD;
    }

    cout << dp[n];
    
    return 0;
}