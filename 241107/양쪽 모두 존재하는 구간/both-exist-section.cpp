#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> arr;
unordered_map<int, int> outer;
unordered_map<int, int> inner;

int main() {
    cin >> n >> m;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        outer[arr[i]]++;
    }

    int j = -1;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < n && inner.size() < m)
        {
            int key = arr[j + 1];
            inner[key]++;
            if (--outer[key] <= 0) 
                outer.erase(key);

            j++;
        }

        if (outer.size() == m && inner.size() == m)
            ans = min(ans, j - i + 1);

        outer[arr[i]]++;
        if (--inner[arr[i]] <= 0)
            inner.erase(arr[i]);
    }

    if (ans == INT_MAX)
        cout << "-1";
    else
        cout << ans;
    
    return 0;
}