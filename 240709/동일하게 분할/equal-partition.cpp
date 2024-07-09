#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cin >> n;


    int sum = 0;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(j >= nums[i] && dp[i - 1][j - nums[i]])
                dp[i][j] = true;
            
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    bool answer = false;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[n][i] && sum - i == i) answer = true;
    }

    if (answer) cout << "Yes";
    else cout << "No";


    return 0;
}