#include <iostream>
using namespace std;

int N;

int getDigit(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }

    return cnt;
}

bool isBeautiful(int num)
{
    int prev = 0;
    int cnt = 0;
    while (num || prev)
    {
        int current = num % 10;
        if (prev && prev != current && cnt % prev != 0) return false;

        cnt = prev == current ? cnt + 1 : 1;
        prev = current;
        num /= 10;
    }

    return true;
}

int solve(int num)
{
    if (getDigit(num) == N) return isBeautiful(num) ? 1 : 0;

    int ret = 0;
    for (int i = 1; i <= 4; i++)
    {
        ret += solve(num * 10 + i);
    }

    return ret;
}

int main() {
    cin >> N;

    cout << solve(0);

    return 0;
}