#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (m.find(x) == m.end())
            m[x] = y;
        else
            m[x] = min(m[x], y);
    }

    long long ans = 0;
    for (const auto& kvp : m)
    {
        ans += kvp.second;
    }

    cout << ans;
    
    return 0;
}