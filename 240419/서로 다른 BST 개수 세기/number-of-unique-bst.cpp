#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    }

    cout << dp[n];

    return 0;
}