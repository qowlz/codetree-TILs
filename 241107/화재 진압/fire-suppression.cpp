#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int getDist(int a, int b)
{
    return abs(b - a);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> station(m, 0);
    for (int i = 0; i < m; i++)
        cin >> station[i];

    sort(arr.begin(), arr.end());
    sort(station.begin(), station.end());

    int j = -1;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int maxP = i + 1 < m ? station[i] + getDist(station[i], station[i + 1]) / 2 : INT_MAX;
        while (j + 1 < n && arr[j + 1] <= maxP)
        {
            j++;
        }

        ans = max(ans, getDist(station[i], arr[j]));
    }

    cout << ans;

    return 0;
}