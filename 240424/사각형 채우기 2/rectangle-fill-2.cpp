#include <iostream>
#include <vector>
using namespace std;

#define MOD 10007

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = ((2 * dp[i - 2] % MOD) + dp[i - 1] % MOD) % MOD;
    }

    cout << dp[n];

    return 0;
}