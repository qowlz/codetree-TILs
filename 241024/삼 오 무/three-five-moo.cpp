#include <iostream>
#include <climits>
using namespace std;

long long getOrder(long long num)
{
    long long moo = num / 3 + num / 5 - num / 15;

    return num - moo;
}

int main() {
    int n;
    cin >> n;
    
    long long left = 1, right = INT_MAX;
    long long ans = INT_MAX;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        auto order = getOrder(mid);
        if (order == n)
        {
            ans = mid;
            break;
        }

        if (order > n)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}