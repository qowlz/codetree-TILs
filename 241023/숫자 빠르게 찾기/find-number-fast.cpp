#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> nums;

int solve(int x)
{
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == x) return mid;

        if (nums[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main() {
    cin >> n >> m;

    nums.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    while (m--)
    {
        int num;
        cin >> num;
        cout << solve(num) << '\n';
    }

    return 0;
}