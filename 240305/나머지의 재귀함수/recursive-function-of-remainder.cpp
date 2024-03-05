#include <iostream>
using namespace std;

int solve(int n)
{
    if (n <= 0) return 0;

    if (n == 1) return 2;
    if (n == 2) return 4;

    return (solve(n - 1) * solve(n - 2)) % 100;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}