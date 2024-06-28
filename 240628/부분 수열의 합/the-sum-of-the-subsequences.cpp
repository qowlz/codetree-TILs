#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> nums;
vector<int> maximum;

bool solve(int idx, int m)
{
    int sub = idx >= 0 ? m - nums[idx] : m;
    if (sub <= 0) return sub == 0;

    for (int i = idx + 1; i < N; i++)
    {
        if (sub > maximum[i]) continue;

        if (solve(i, sub)) return true;
    }

    return false;
}

int main() {
    cin >> N >> M;

    nums.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int sum = 0;
    maximum.assign(N, 0);
    for (int i = N - 1; i >= 0; i--)
    {
        sum += nums[i];
        maximum[i] = sum;
    }

    if (solve(-1, M))
        cout << "Yes";
    else
        cout << "No";
    

    return 0;
}