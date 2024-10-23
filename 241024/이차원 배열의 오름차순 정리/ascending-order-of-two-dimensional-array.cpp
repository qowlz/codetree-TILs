#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long low = 1, high = 1e10;
    long long ans = high + 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;

        long long order = 0;
        for (long long i = 1; i <= n; i++)
            order += min(n, mid / i);
        
        if (order >= k)
        {
            high = mid - 1;
            ans = min(ans, mid);
        }
        else
            low = mid + 1;
    }

    cout << ans;

    return 0;
}