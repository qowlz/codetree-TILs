#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, k;
vector<int> arr;

int main() {
    cin >> n >> k;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int one = 0;
    int j = -1;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < n && one < k)
        {
            if (arr[++j] == 1) one++;
        }

        if (one >= k) ans = min(ans, j - i + 1);

        if (arr[i] == 1) one--;
    }

    if (ans == INT_MAX)
        cout << "-1";
    else
        cout << ans;

    return 0;
}