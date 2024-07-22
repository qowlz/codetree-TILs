#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> str2idx;
    unordered_map<int, string> idx2str;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        str2idx[str] = i;
        idx2str[i] = str;
    }

    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9')
            cout << idx2str[stoi(str)];
        else
            cout << str2idx[str];
        
        cout << '\n';
    }

    return 0;
}