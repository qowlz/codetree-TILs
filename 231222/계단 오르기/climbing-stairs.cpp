#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 1000;
    long long dp[MAX + 1] = {0};
    dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}