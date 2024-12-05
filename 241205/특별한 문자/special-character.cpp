#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    cin >> str;

    unordered_map<char, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }

    bool none = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (m[str[i]] == 1)
        {
            none = false;
            cout << str[i];
            break;
        }
    }

    if (none) cout << "None";
    
    return 0;
}