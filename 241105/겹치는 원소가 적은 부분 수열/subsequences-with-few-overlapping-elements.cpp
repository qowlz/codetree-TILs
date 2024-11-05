#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> arr;
unordered_map<int, int> m;

int main() {
    cin >> n >> k;
    
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(j + 1 < n && m[arr[j + 1]] + 1 <= k)
        {
            m[arr[++j]]++;
        }

        ans = max(ans, j - i + 1);

        m[arr[i]]--;
    }

    cout << ans;


    return 0;
}