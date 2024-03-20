#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 6

string ex;
int a2n[MAX_N] = {0};

int calc(int a, int b, char op)
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;

    return a;
}

int solve(int idx)
{
    if (idx >= MAX_N) 
    {
        char op = '+';
        int result = 0;
        for (int i = 0; i < ex.length(); i++)
        {
            if (ex[i] >= 'a' && ex[i] <= 'f') 
                result = calc(result, a2n[ex[i] - 'a'], op);
            else
                op = ex[i];
        }

        return result;
    }

    int ret = INT_MIN;
    for (int i = 1; i <= 4; i++)
    {
        a2n[idx] = i;
        ret = max(ret, solve(idx + 1));
        a2n[idx] = 0;
    }

    return ret;
}

int main() {
    cin >> ex; 

    cout << solve(0);

    return 0;
}