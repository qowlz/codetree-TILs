#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<int> arr;

bool isPossible(long long t)
{
    long long cnt = 0;
    for (int i = 0; i < m; i++)
        cnt += t / arr[i];
    
    return cnt >= n;
}


int main() {
    cin >> n >> m;

    arr.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    
    long long left = 1, right = 1e15;
    long long ans = right + 1;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
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