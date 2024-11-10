#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> S(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i -1][j - 1] + arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - k < 0 || j - k < 0) continue;

            ans = max(ans, S[i][j] - (S[i - k][j] + S[i][j - k] - S[i - k][j - k]));
        }
    }

    cout << ans;

    return 0;
}