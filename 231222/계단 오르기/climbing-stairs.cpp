#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 1000;
    int dp[MAX + 1] = {0};
    dp[0] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 3] + dp[i - 2];

    cout << dp[n] % 10007;

    return 0;
}