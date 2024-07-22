#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    unordered_map<int, int> m;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "add")
        {
            int k, v;
            cin >> k >> v;
            m[k] = v;
        }
        else if (cmd == "remove")
        {
            int k;
            cin >> k;

            m.erase(k);
        }
        else if (cmd == "find")
        {
            int k;
            cin >> k;

            if (m.find(k) != m.end())
                cout << m[k] << '\n';
            else
                cout << "None" << '\n';
        }
    }

    return 0;
}