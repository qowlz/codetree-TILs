#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

int main() {
    // cin >> n >> k;
    scanf("%d %d", &n, &k);

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int j = -1;
    vector<pair<int, int>> groups;
    for (int i = 0; i < n; i++)
    {
        while(j + 1 < n && arr[j + 1] - arr[i] <= k) j++;

        groups.push_back({i, j});
    }

    int ans = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        for (int j = i + 1; j < groups.size(); j++)
        {
            if (groups[j].first > groups[i].second || groups[j].second < groups[i].first)
            {
                int a = groups[i].second - groups[i].first + 1;
                int b = groups[j].second - groups[j].first + 1;
                ans = max(ans, a + b);
            }
        }
    }

    // cout << ans;
    printf("%d", ans);

    return 0;
}