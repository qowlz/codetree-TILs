#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

int main() {
    cin >> n >> k;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> L(n, 0);
    int i = 0, max_num = 0;
    for (int j = 0; j < n; j++)
    {
        while(i <= j && arr[j] - arr[i] > k)
            i++;
        
        max_num = max(max_num, j - i + 1);
        L[j] = max_num;
    }

    int j = n - 1;
    vector<int> R(n, 0);
    max_num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j >= i && arr[j] - arr[i] > k)
            j--;
        
        max_num = max(max_num, j - i + 1);
        R[i] = max_num;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, L[i] + R[i + 1]);
    }

    cout << ans;

    return 0;
}