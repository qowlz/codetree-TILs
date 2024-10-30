#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

bool isPossible(int mid)
{
    int total = 1;
    int s = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - s > mid * 2)
        {
            s = arr[i];
            total++;
        }
    }

    return total <= k;
}


int main() {
    cin >> n >> k;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int left = 0, right = 1e9;
    int ans = right;
    while (left <= right)
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