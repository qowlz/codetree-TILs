#include <iostream>
#include <vector>
using namespace std;

vector<int> cached;

int solve(int n)
{
    if (n <= 0) return 0;
    if (cached[n]) return cached[n];

    return cached[n] = (solve(n - 1) * solve(n - 2)) % 100;
}

int main() {
    int n;
    cin >> n;

    cached.resize(n + 2);
    cached[1] = 2; cached[2] = 4;
    cout << solve(n);

    return 0;
}