#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({e, s});
    }

    sort(arr.begin(), arr.end());

    int t = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        tie(e, s) = arr[i];

        if (t <= s)
        {
            t = e;
            ans++;
        }
    }

    cout << ans;

    return 0;
}