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

int getIdeal(int acc, char op)
{
    if (op == '+' || (acc >= 0 && op == '*')) return 4;

    return 1;
}

int solve(int idx, int acc)
{
    if (idx + 2 >= ex.length()) return acc;

    char op = inRange(idx + 1) ? ex[idx + 1] : '+';
    int b = getIdeal(acc, op);
    int ret = max(ret, solve(idx + 2, calc(acc, b, op)));

    return ret;
}


int main() {
    cin >> ex; 

    cout << solve(-2, 0);

    return 0;
}