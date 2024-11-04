#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    int j = 0;
    unordered_set<char> unique;
    for (int i = 0; i < s.length(); i++)
    {
        while(j < s.length() && unique.find(s[j]) == unique.end())
        {
            unique.insert(s[j]);
            j++;
        }

        ans = max(ans, j - i);

        unique.erase(s[i]);
    }

    cout << ans;

    return 0;
}