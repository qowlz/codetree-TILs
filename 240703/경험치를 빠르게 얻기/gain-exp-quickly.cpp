#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<int> e(n + 1, 0);
    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> e[i] >> t[i];
    
    // dp[i][j]: 퀘스트 i까지 고려했을 때, 경험치 j이상을 얻을 수 있는 최소 시간
    // dp[i][j] = min(t[i] + dp[i - 1][j - e[i]], dp[i - 1][j])
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // 나 자신을 선택하는 경우
        // 얻는 경험치가 더 큰 경우
            // 멈추는게 무조건 이득
            // 더 수행해봤자 초만 늘어난다.
            // 고로, t[i]
        // 얻는 경험치가 더 작은 경우
            // t[i] + dp[i - 1][j - e[i]]를 해야함
            // 경험치가 모자라는 만큼 매꿔야해서
    // 나 자신을 선택하지 않는 경우
        // dp[i - 1][j]
        // 요것만 체크하면됨

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 자기 자신을 선택하는 경우
            if (e[i] >= j)
                dp[i][j] = t[i];
            else if (dp[i - 1][j - e[i]] != INT_MAX)
                dp[i][j] = t[i] + dp[i - 1][j - e[i]];
            
            // 자기 자신을 선택하지 않는 경우
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                
            // cout << "dp[" << i << "]" << "[" << j << "]: " << dp[i][j] << endl;
        }
    }

    if (dp[n][m] == INT_MAX)
        cout << "-1";
    else
        cout << dp[n][m];

    return 0;
}