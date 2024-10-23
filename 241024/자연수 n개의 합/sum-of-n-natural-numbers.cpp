#include <iostream>
#include <climits>
using namespace std;

int main() {
    int s;
    cin >> s;

    long long left = 1, right = 1e10;
    long long maxIdx = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (mid * (mid + 1) / 2 <= s)
        {
            left = mid + 1;
            maxIdx = max(maxIdx, mid);
        }
        else
            right = mid - 1;
    }

    cout << maxIdx;

    return 0;
}