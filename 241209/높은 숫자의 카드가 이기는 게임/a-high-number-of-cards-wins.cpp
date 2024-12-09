#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> s;
    for (int i = 1; i <= 2 * n; i++)
        s.insert(i);
    
    vector<int> arr(n); // b가 낸 카드들
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.erase(arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(arr[i]);
        if (it == s.end())
        {
            s.erase(*s.begin());
        }
        else
        {
            s.erase(*it);
            ans++;
        }
    }

    cout << ans;
    
    return 0;
}