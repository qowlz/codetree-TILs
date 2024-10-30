#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> merged;
vector<vector<int>> dp;

// dp[i][j] = i부터 j까지의 구간 중 필요한 최소 비용
// dp[i][j] = dp[1][k] + dp[k + 1][j] + merged[1][k] + merged[k + 1][j]

int solve(int i, int j)
{
    if (i == j) return dp[i][j] = 0;

    if (dp[i][j] != -1) return dp[i][j];

    int best = 1e9;
    for (int k = i; k < j; k++)
        best = min(best, solve(i, k) + solve(k + 1, j) + merged[i][k] + merged[k + 1][j]);

    return dp[i][j] = best;
}


int main() {
    cin >> n;

    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    merged.assign(n + 1, vector<int>(n + 1, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = i + gap;
            if (j > n) continue;

            if (i == j) merged[i][j] = arr[i];
            else merged[i][j] = merged[i][j - 1] + arr[j];
        }
    }

    dp.assign(n + 1, vector<int>(n + 1, -1));
    cout << solve(1, n);

    return 0;
}