#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int ans = 0;
    int j = -1;
    unordered_map<char, int> m;
    m.clear();
    for (int i = 0; i < s.length(); i++)
    {
        while(j + 1 < s.length())
        {
            int kind = m.find(s[j + 1]) == m.end() ? m.size() + 1: m.size();
            if (kind > k) break;

            m[s[++j]]++;
        }

        ans = max(ans, j - i + 1);

        if (--m[s[i]] <= 0) m.erase(s[i]);
    }

    cout << ans;

    return 0;
}