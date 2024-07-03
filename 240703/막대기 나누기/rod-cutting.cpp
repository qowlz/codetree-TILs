#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;

    vector<int>v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    
    // dp[n]: 길이가 n인 막대기를 팔았을 때 얻을 수 있는 최대 수익
    // dp[n] = max(그대로 파는 경우, 잘라서 파는 경우)
    // 잘라서 파는 경우 = max()

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int maximum = 0;
        for (int j = 1; j <= i; j++)
        {
            maximum = max(maximum, v[j] + dp[i - j]);
        }

        dp[i] = maximum;
        // cout <<"dp[" << i << "]: " <<  dp[i] << endl;
    }

    cout << dp[n];

    return 0;
}