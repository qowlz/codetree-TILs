#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m = 0;
    cin >> n >> m;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > i) continue;

            int val = dp[i - arr[j]] < 0 ? INT_MAX : dp[i - arr[j]] + 1;
            minimum = min(minimum, val);
        }

        dp[i] = minimum == INT_MAX ? -1 : minimum;
    }

    cout << dp[m];

    return 0;
}