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
        int a = dp[i - 1] == INT_MIN ? nums[i] : dp[i - 1] + nums[i];
        dp[i] = max(a, nums[i]);
    }

    int answer = INT_MIN;
    for (int i = 1; i <= n; i++)
        answer = max(dp[i], answer);

    cout << answer;
    
    return 0;
}