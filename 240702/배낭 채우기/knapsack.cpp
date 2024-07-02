#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> w(n, 0);
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        dp[0][i] = i >= w[0] ? v[0] : 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= w[i]) dp[i][j] = v[i] + dp[i - 1][j - w[i]];

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[i][m]);
    }

    cout << answer;

    return 0;
}