#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> dp(n, 1);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] <= arr[i]) continue;

            dp[i] = max(dp[i], dp[j] + 1);
        }
        
        // cout << "dp[" << i << "]: " << dp[i] << endl;
    }

    cout << dp[0];

    return 0;
}