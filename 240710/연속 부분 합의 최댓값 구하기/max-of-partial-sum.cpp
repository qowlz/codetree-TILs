#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    
    vector<int> dp(n + 1, INT_MIN);
    for (int i = 1; i <= n; i++)
    {
        // i를 선택하는 경우
        int cmp = dp[i - 1] == INT_MIN ? nums[i] : dp[i - 1] + nums[i];
        dp[i] = max(cmp, nums[i]);


        // i를 선택하지 않은 경우
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n];
    
    return 0;
}