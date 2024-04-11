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

    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            int val = i / arr[j] + dp[i % arr[j]];
            minimum = val ? min(minimum, val) : minimum;
        }

        dp[i] = minimum == INT_MAX ? 0 : minimum;
    }

    if (dp[m]) cout << dp[m];
    else cout << "-1";

    return 0;
}