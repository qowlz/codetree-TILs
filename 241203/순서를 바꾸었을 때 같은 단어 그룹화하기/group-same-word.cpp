#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> m;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        int key = 0;
        for (int i = 0; i < str.length(); i++)
            key += (int)str[i];
        
        m[key]++;
    }

    int ans = 0;
    for (auto& p : m)
        ans = max(ans, p.second);

    cout << ans;

    return 0;
}