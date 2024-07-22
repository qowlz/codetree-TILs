#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        m[str]++;
    }

    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        ans = max(it->second, ans);
    }

    cout << ans;

    return 0;
}