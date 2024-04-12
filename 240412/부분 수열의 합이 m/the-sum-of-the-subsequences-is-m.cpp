#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_ANS 101

int N, M;
vector<int> arr;
vector<vector<int>> dp;

int main() {
    cin >> N >> M;

    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp.assign(M + 1, vector<int>(N + 1, MAX_ANS));
    for (int i = 0; i <= N; i++) dp[0][i] = 0;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = j; k < N; k++)
            {
                if (arr[k] > i) continue;

                dp[i][j] = min(dp[i][j], 1 + dp[i - arr[k]][k + 1]);
            }
        }
    }

    int answer = MAX_ANS;
    for (int i = 0; i < N; i++) answer = min(answer, dp[M][i]);

    answer = answer == MAX_ANS ? -1 : answer;
    cout << answer;

    return 0;
}