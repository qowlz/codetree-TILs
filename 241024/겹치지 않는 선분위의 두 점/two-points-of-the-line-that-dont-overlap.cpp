#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
vector<pair<long long, long long>> arr;

bool isPossible(long long d)
{
    int cnt = 1;
    long long last = arr[0].first;
    for (int i = 0; i < m; i++)
    {
        long long a, b;
        tie(a, b) = arr[i];

        // 초기 점 위치 세팅
        if (a - last >= d)
        {
            cnt++;
            last = a;
        }

        while (last + d <= b)
        {
            cnt++;
            last += d;
            // cout << "\tselect: " << last << endl;
        }
    }

    // cout << "\tcnt: " << cnt << endl;
    return cnt >= n;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    
    sort(arr.begin(), arr.end());
    
    long long left = 0, right = 100; // 1e18
    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        // cout << "mid: " << mid << endl;
        if (isPossible(mid))
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