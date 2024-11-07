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

bool isNear(int i, int j)
{
    if (i + 1 >= m) return true;
    
    return getDist(station[i], arr[j]) < getDist(station[i + 1], arr[j]);
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
    for (int i = 0; i < m; i++)
    {
        while (j + 1 < n && isNear(i, j + 1))
        {
            j++;
        }

        if(j < n) ans = max(ans, getDist(station[i], arr[j]));

        j++;
    }

    cout << ans;

    return 0;
}