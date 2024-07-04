#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> w(n, 0);
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];


    // dp[m]: 무게의 합이 m을 넘지 않으면서 얻을 수 있는 최대 가치
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (w[j] > i) continue;

            dp[i] = max(dp[i], v[j] + dp[i - w[j]]);
        }
    }

    cout << dp[m];

    return 0;
}