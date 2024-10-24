#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

bool isPossible(int d)
{
    int cnt = 1;
    int lastIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[lastIdx] >= d)
        {
            cnt++;
            lastIdx = i;
        }
    }

    return cnt >= m;
}

int main() {
    cin >> n >> m;

    arr.assign(n, 0);
    for (int i = 0 ; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    int lo = 0, hi = 1e9;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(isPossible(mid))
        {
            lo = mid + 1;
            ans = max(ans, mid);
        }
        else
            hi = mid - 1;
    }

    cout << ans;

    return 0;
}