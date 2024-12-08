#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<unsigned int> arr(n);
    map<unsigned int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long long result = m.rbegin()->first - arr[i];
        // cout << "best: " << m.rbegin()->first << endl;
        
        if (result > 0) ans = max(ans, result);

        if (--m[arr[i]] <= 0)
            m.erase(arr[i]);
    }

    cout << ans;

    return 0;
}