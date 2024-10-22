#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long m;

long long solve(int x)
{
    long long left = 1, right = m;
    long long cnt = 0;
    while (left <= right)
    {
        cnt++;

        long long mid = (left + right) / 2;
        if (mid == x) break;

        if (mid >= x)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return cnt;
}

int main()
{
    cin >> m;

    long long a, b;
    cin >> a >> b;

    long long min_ans = LLONG_MAX;
    long long max_ans = 0;
    for (long long i = a; i <= b; i++)
    {
        auto c = solve(i);
        min_ans = min(min_ans, c);
        max_ans = max(max_ans, c);
    }

    cout << min_ans << ' ' << max_ans;
}