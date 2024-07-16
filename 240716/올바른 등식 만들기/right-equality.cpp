#include <iostream>
#include <vector>
using namespace std;

#define MAX_M 40


bool inRange(int num, int low, int high)
{
    return low <= num && num <= high;
}


// 1 + 1 + 1 = 3
// 1 + 1 - 1 = 1
// 1 - 1 + 1 = 1
// 1 - 1 - 1 = -1

// -1 + 1 + 1 = 1
// -1 + 1 - 1 = -1
// -1 - 1 + 1 = -1
// -1 - 1 - 1 = -3
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    vector<vector<long long>> dp(n + 1, vector<long long>(MAX_M + 1, 0));
    dp[0][20] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= MAX_M; j++)
        {
            // 더하는 경우
            int rest1 = (j - 20) - arr[i];
            if (inRange(rest1, -20, 20))
                dp[i][j] += dp[i - 1][rest1 + 20];

            // 빼는 경우
            int rest2 = (j - 20) + arr[i];
            if (inRange(rest2, -20, 20))
                dp[i][j] += dp[i - 1][rest2 + 20];

            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
        }
    }

    cout << dp[n][m + 20];

    return 0;
}