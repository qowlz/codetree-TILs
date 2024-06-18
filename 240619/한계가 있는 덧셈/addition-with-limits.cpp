#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;

// greedy?
// greedy가 성립이 되려면 앞에 총합이 큰 숫자를 선택했을 때, 앞에서 큰 숫자를 썻으므로 뒤에서 손해를 보는 패턴이 눈에 보여야한다.
// 4 4
// 6 5 4 3 2 
int solve(int idx, int score)
{
    if (idx >= N) return score;

    // 안 건너뛰는 경우
    int a = 0;
    int idxA = idx;
    for (int i = idx; i < N; i++)
    {
        if (a >= K) break;

        a += arr[i];
        idxA = i;
    }

    // 건너뛰는 경우
    int b = 0;
    int idxB = idx;
    for (int i = idx + 1; i < N; i++)
    {
        if (b >= K) break;

        b += arr[i];
        idxB = i;
    }

    if (a > b)
        return solve(idxA + 1, score + (a - K));
    else
        return solve(idxB + 1, score + (b - K));
}


int main() {
    cin >> N >> K;

    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    cout << solve(0, 0);

    return 0;
}