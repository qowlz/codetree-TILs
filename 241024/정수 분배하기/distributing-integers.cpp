#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int limit = 0;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        limit = max(limit, arr[i]);
    }

    int left = 1, right = limit; 
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        int total = 0;
        for (int i = 0; i < n; i++)
            total += arr[i] / mid;
        
        if (total >= m)
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}