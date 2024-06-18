#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;

// 4 8
// 1 5 3 2
// 1 - 5 - 3 - 2
// 5 - 3 - 2
int solve(int idx, int acc, int score)
{
    if (idx >= N) return score;

    if (idx >= 0)
    {
        acc += arr[idx];
        // cout << "idx: " << idx << " acc: " << acc << endl;
    }

    int get = 0;
    if (acc >= K)
    {
        get = acc - K;
        score += get;
        acc = 0;
    }

    if (get > 0 || idx < 0) 
        return max(solve(idx + 1, acc, score), solve(idx + 2, acc, score));
    else 
        return solve(idx + 1, acc, score);
}


int main() {
    cin >> N >> K;

    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    cout << solve(-1, 0, 0);

    return 0;
}