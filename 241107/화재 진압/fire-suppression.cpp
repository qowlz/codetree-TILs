#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> station;
vector<int> arr;

int getDist(int a, int b)
{
    return abs(b - a);
}

int main() {
    cin >> n >> m;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    station.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> station[i];

    sort(arr.begin(), arr.end());
    sort(station.begin(), station.end());

    int j = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int minD = j < 0 ? INT_MAX : getDist(arr[i], station[j]);
        while (j + 1 < m && getDist(arr[i], station[j + 1]) <= minD)
        {
            minD = getDist(arr[i], station[++j]);
        }

        ans = max(ans, getDist(arr[i], station[j]));
    }

    cout << ans;

    return 0;
}