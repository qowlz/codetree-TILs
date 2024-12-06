#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        arr[i] = {w, v};
    }

    vector<pair<double, int>> sorted;
    for (int i = 0; i < n; i++)
    {
        auto& item = arr[i];
        sorted.push_back({item.second / (double)item.first, i});
    }

    sort(sorted.begin(), sorted.end(), greater<>());

    int totalWeight = 0;
    double ans = 0;
    for (auto& item : sorted)
    {
        double vpw = item.first;
        int idx = item.second;
        if (totalWeight + arr[idx].first > m)
        {
            ans += (m - totalWeight) * vpw;
            break;
        }

        totalWeight += arr[idx].first;
        ans += arr[idx].second;
    }

    cout << fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}