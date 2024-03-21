#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<int> arr;

int solve(int idx, int jump)
{
    if (idx >= arr.size()) return INT_MAX;

    if (idx == arr.size() - 1) return jump;

    int ret = INT_MAX;
    for (int i = 1; i <= arr[idx]; i++)
        ret = min(ret, solve(idx + i, jump + 1));

    return ret;
}

int main() {
    cin >> N;

    arr.assign(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];

    auto answer = solve(0, 0);
    answer = answer == INT_MAX ? -1 : answer;
    cout << answer;

    return 0;
}