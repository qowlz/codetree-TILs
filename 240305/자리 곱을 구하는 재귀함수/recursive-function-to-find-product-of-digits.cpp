#include <iostream>
using namespace std;

int solve(int num, int result)
{
    if (num <= 0) return result;

    int remain = num % 10;
    return solve(num / 10, remain != 0 ? result * remain : result);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    cout << solve(n1 * n2 * n3, 1);

    return 0;
}