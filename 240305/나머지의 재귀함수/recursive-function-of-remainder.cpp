#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cached;

long long solve(int n)
{
    if (n <= 0) return 0;
    if (cached[n]) return cached[n];

    return cached[n] = (solve(n - 1) * solve(n - 2)) % 100;
}

int main() {
    int n;
    cin >> n;

    cached.resize(max(n, 3));
    cached[1] = 2; cached[2] = 4;
    cout << solve(n);

    return 0;
}