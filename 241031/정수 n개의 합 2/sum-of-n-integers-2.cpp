#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1, 0);
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= n - (k - 1); i++)
    {
        ans = max(ans, prefix_sum[i + (k - 1)] - prefix_sum[i] + arr[i]);
    }

    cout << ans;


    return 0;
}