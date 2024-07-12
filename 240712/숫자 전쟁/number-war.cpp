/*
dp[i][j]: 상대방 카드를 i까지 고려하고 내 카드를 j까지 고려 할 때 나올 수 있는 최대합

dp[i][j]: 상대방 i와 j를 비교한다고 쳤을 때, 최대합을 어떻게 가져와야 좋은가? 
dp[i - 1][j - 1]과 더하면 될거같은디?

말이 된다의 기준은 dp[i - 1][j - 1]이 음수냐 아니냐?

dp[i][j] 경우의 수
    Case 1(카드 대결)
        i - 1 / j 상태로 카드 비교를 하고, i - 1의 숫자가 더 작아 넘어왔을 경우
            이 경우에는 점수를 얻지 않음
        i / j - 1 상태로 카드 비교를 하고, j - 1의 숫자가 더 작아 넘어왔을 경우
            이 경우에는 무조건 점수를 얻었을 거임
        i - 1 / j - 1 상태로 카드 비교를 하고 두개의 숫자가 같았을 경우
            이 경우에도 점수를 얻지 않음

    Case 2(카드 버리기)
        i - 1 / j - 1인 상태로 카드 버리기를 했을 경우
            점수를 얻지 않음


테스트 케이스
-----------------------------------
4
3 2 5 1
4 6 4 4

dp[1][1] = 0
dp[1][2] = -1
dp[1][3] = -1
dp[1][4] = -1

dp[2][1] = 0
dp[2][2] = 0
dp[2][3] = -1
dp[2][4] = -1

dp[3][1] = max(4 + 0, -1. -1) = 4
dp[3][2] = max(0 + 0, 0 + 4, 0 + 0) = 4
dp[3][3] = max(-1, 4 + 4, 4 + 0) = 8 // 얘는 여기서 선택이안된다. 중간의 6 때문에;
dp[3][4] = max(-1. 4 + 8, -1) = 12

dp[4][1] = 0
dp[4][2] = 0
dp[4][3] = 0
dp[4][4] = 0


-----------------------------------


*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    vector<int> other(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> other[i];
    
    vector<int> my(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> my[i];
    

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int add = my[j] < other[i] ? my[j] : 0;

            if (other[i - 1] < my[j])
                dp[i][j] = add + dp[i - 1][j];
            
            if (my[j - 1] < other[i])
                dp[i][j] = max(dp[i][j], add + dp[i][j - 1]);
            

            if (dp[i - 1][j - 1] >= 0)
                dp[i][j] = max(dp[i][j], add +dp[i - 1][j - 1]);            


            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[i][n]);
    
    cout << answer;

    return 0;
}