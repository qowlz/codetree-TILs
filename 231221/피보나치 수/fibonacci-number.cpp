#include <iostream>
using namespace std;

int memo[46];

int fib(int n)
{
    if (memo[n]) return memo[n];
    
    if (n <= 2) return 1;

    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << fib(n);

    return 0;
}