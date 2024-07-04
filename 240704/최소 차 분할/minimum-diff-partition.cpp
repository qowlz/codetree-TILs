#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int sum = 0;
int answer = INT_MAX;
vector<int> nums;

void solve(int idx, int acc)
{
    if (idx >= n) return;

    int sumA = acc + nums[idx];
    int sumB = sum - sumA;
    answer = min(answer, abs(sumB - sumA));

    for (int i = idx + 1; i < n; i++)
        solve(i, sumA);
}


int main() {
    cin >> n;

    nums.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    solve(0, 0);

    cout << answer;

    


    return 0;
}