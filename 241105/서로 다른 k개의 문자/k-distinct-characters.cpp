#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string str;
int k;

int main() {
    cin >> str >> k;

    int ans = 0;
    int j = 0;
    unordered_set<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        while (j < str.length())
        {
            int kind = s.find(str[j]) == s.end() ? s.size() + 1 : s.size();
            if (kind > k) break;

            s.insert(str[j]);
            j++;
        }

        ans = max(ans, j - i);

        s.erase(str[i]);
    }

    cout << ans;

    return 0;
}