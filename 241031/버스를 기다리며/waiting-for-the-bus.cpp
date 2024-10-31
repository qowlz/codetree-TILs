#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c;
vector<int> arr;

bool isPossible(int mid)
{
    int cnt = 1;
    int wait = 1;
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (wait == c || arr[i] - arr[idx] > mid)
        {
            cnt++;
            wait = 1;
            idx = i;
        }
        else
            wait++;
    }

    return cnt <= m;
}


int main() {
    cin >> n >> m >> c;
    
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    int left = 0, right = 1e9;
    int ans = right;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (isPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;

    
    return 0;
}