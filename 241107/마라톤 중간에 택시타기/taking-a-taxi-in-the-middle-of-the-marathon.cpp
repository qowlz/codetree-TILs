#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;

int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(b.first - a.first) + abs(b.second - a.second);
}

int main() {
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> L(n, 0);
    for (int i = 1; i < n; i++)
    {
        L[i] = L[i - 1] + dist(arr[i], arr[i - 1]);
    }

    vector<int> R(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        R[i] = R[i + 1] + dist(arr[i], arr[i + 1]);
    }

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, L[i - 1] + R[i + 1] + dist(arr[i - 1], arr[i + 1]));
    }

    cout << ans;

    return 0;
}