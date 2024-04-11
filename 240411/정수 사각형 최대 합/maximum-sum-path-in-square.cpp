#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<int>> dp;

int main() {
    cin >> N;

    arr.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    dp.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
            dp[i][j] = arr[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
    }

    cout << dp[0][0];

    return 0;
}