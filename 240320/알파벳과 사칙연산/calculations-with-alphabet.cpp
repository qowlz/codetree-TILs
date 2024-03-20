#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ex;

bool inRange(int idx)
{
    return idx >= 0 || idx < ex.length();
}

int calc(int a, int b, char op)
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;

    return a + b;
}

int solve(int idx, int acc)
{
    if (idx + 2 >= ex.length()) return acc;

    int ret = acc;
    for (int i = 1; i <= 4; i++)
    {
        char op = inRange(idx + 1) ? ex[idx + 1] : '+';
        ret = max(ret, solve(idx + 2, calc(acc, i, op)));
    }

    return ret;
}


int main() {
    cin >> ex; 

    cout << solve(-2, 0);

    return 0;
}