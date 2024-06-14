#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;

int solve(int idx, int acc, int score)
{
    if (idx >= N) return score;

    if (idx >= 0) acc += arr[idx];

    int get = 0;
    if (acc >= K)
    {
        get = acc - K;
        score += get;
        acc = 0;
    }

    return max(solve(idx + 1, acc, score), solve(idx + 2, acc, score));
}


int main() {
    cin >> N >> K;

    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    cout << solve(-1, 0, 0);

    return 0;
}