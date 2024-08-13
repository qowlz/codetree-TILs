#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, D;

int main() {
    cin >> N >> D;

    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({y, x});
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = N - 1;
    int answer = INT_MAX;
    while (l < r)
    {
        int diff = abs(arr[r].first - arr[l].first);
        if (diff < D) break;

        answer = min(answer, abs(arr[r].second - arr[l].second));
        r--;
    }

    if (answer == INT_MAX)
        cout << "-1";
    else
        cout << answer;

    return 0;
}