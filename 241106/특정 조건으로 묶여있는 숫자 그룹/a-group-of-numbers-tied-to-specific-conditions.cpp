#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

int main() {
    cin >> n >> k;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int j = -1;
    vector<pair<int, int>> groups;
    vector<int> l(n, 1);
    for (int i = 0; i < n; i++)
    {
        while(j + 1 < n && arr[j + 1] - arr[i] <= k) j++;

        l[i] = max(l[i], j - i + 1);

        groups.push_back({i, j});
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a = groups[i].second - groups[i].first + 1;
        if (groups[i].second < n)
            ans = max(ans, a + l[groups[i].second + 1]);
        else
            ans = max(ans, a);
    }

    cout << ans;

    return 0;
}