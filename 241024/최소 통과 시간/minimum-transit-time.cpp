#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<int> arr;

bool isPossible(int t)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
        cnt += t / arr[i];
    
    return cnt >= n;
}


int main() {
    cin >> n >> m;

    arr.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    
    int left = 0, right = 1e9;
    int ans = INT_MAX;
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