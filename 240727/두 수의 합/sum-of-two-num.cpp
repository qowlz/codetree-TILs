#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<long long, int> m;
    vector<long long> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        m[nums[i]]++;
    }

    int ans = 0;
    for (const auto& num : nums)
    {
        m[num]--;

        long long sub = k - num;
        if (m[sub]) ans += m[sub];
    }

    cout << ans;

    return 0;
}