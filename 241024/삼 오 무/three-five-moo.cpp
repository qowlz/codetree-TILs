#include <iostream>
#include <climits>
using namespace std;

int getMoo(int num)
{
    return num / 3 + num / 5 - num / 15;
}

int main() {
    int n;
    cin >> n;
    
    int left = 1, right = INT_MAX;
    long long ans = INT_MAX;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long order = mid - getMoo(mid);

        if (order >= n)
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