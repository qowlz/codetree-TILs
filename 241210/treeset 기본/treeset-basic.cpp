#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "remove")
        {
            int x;
            cin >> x;

            s.erase(x);
        }
        else if (cmd == "find")
        {
            int x;
            cin >> x;
            
            if (s.find(x) == s.end())
                cout << "false\n";
            else
                cout << "true\n";
        }
        else if (cmd == "lower_bound")
        {
            int x;
            cin >> x;

            auto it = s.lower_bound(x);
            if (it == s.end())
                cout << "None\n";
            else
                cout << *it << '\n';
        }
        else if (cmd == "upper_bound")
        {
            int x;
            cin >> x;

            auto it = s.upper_bound(x);
            if (it == s.end())
                cout << "None\n";
            else
                cout << *it << '\n';
        }
        else if (cmd == "largest")
        {
            if (!s.empty())
                cout << *s.rbegin() << '\n';
            else
                cout << "None\n";
        }
        else if (cmd == "smallest")
        {
            if (!s.empty())
                cout << *s.begin() << '\n';
            else
                cout << "None\n";
        }
    }

    return 0;
}