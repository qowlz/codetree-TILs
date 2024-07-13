#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // dp[i][j]: i번째 숫자를 선택했고, 음수를 j개 선택 했을 때 나올 수 있는 최대 연속합.
    int answer = 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            // 숫자를 선택한 경우
            if (arr[i] > 0) // 양수를 선택한 경우
                dp[i][j] = arr[i] + dp[i - 1][j];
            else if (j > 0) // 음수를 선택한 경우
                dp[i][j] = arr[i] + dp[i - 1][j - 1];

            answer = max(answer, dp[i][j]);
        }
    }
    
    cout << answer;

    return 0;
}