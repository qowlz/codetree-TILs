#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

bool isPossible(long long d)
{
    int cnt = 1;
    long long last = arr[0].first;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        tie(a, b) = arr[i];

        if (a - last >= d)
        {
            cnt++;
            last = a;
        }
        else if (last + d <= b)
        {
            cnt++;
            last += d;
        }

        // cout << "\tselect: " << last << endl;
    }

    return cnt >= n;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        arr.push_back({x1, x2});
    }

    sort(arr.begin(), arr.end());

    int left = 1, right = 1e9; // 1e9
    long long ans = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        // cout << "mid: " << mid << endl;
        if (isPossible(mid))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid -1;
    }

    cout << ans;

    return 0;
}