#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

unsigned long long m;

unsigned long long solve(unsigned long long x)
{
    unsigned long long left = 1, right = m;
    unsigned long long cnt = 0;
    while (left <= right)
    {
        cnt++;

        unsigned long long mid = (left + right) / 2;
        if (mid == x) break;

        if (mid > x)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return cnt;
}

int main()
{
    cin >> m;

    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long min_ans = ULLONG_MAX;
    unsigned long long max_ans = 0;
    for (unsigned long long i = a; i <= b; i++)
    {
        auto c = solve(i);
        min_ans = min(min_ans, c);
        max_ans = max(max_ans, c);
    }

    cout << min_ans << ' ' << max_ans;
}