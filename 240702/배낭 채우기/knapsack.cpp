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

    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if(j == k || w[k] > i) continue;

                dp[i][j] = max(dp[i][j], v[k] + dp[i - w[k]][k]);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[m][i]);
    }

    cout << answer;

    return 0;
}