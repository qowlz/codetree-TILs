#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int p, l;
        cin >> p >> l;
        s.insert({l, p});
    }
    
    int m;
    cin >> m;

    string cmd;
    while(m--)
    {
        cin >> cmd;

        if (cmd == "rc")
        {
            int x;
            cin >> x;
            if (x > 0) cout << (*s.rbegin()).second << '\n';
            else cout << (*s.begin()).second << '\n'; 
        }
        else if (cmd == "ad")
        {
            int p, l;
            cin >> p >> l;
            s.insert({l, p});
        }
        else if (cmd == "sv")
        {
            int p, l;
            cin >> p >> l;
            s.erase({l, p});
        }
    }


    return 0;
}