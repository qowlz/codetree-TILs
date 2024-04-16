#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i -1] % 10007 + dp[i - 2] % 10007;

    cout << dp[n];

    // dp[i] = 2xi의 경우를 채울 수 있는 방법의 수
    // dp[i] = dp[i - 1] + dp[i - 2];

    // 2 x 1인 경우
        // 2 x 1로 밖에 못채운다
        // 총 1가지
    // 2 x 2인 경우
        // 2 x 1 2개
        // 1 x 2 2개
        // 총 2가지
    // 2 x 3인 경우


    return 0;
}