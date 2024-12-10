#include <iostream>
#include <set>
using namespace std;

set<int> s;

void process(const string& cmd, const int& arg)
{
    if (cmd == "I")
    {
        s.insert(arg);
    }
    else if (cmd == "D" && !s.empty())
    {
        if (arg < 0)
            s.erase(*s.begin());
        else
            s.erase(*s.rbegin());
    }
}

int main() {

    int t;
    cin >> t;

    while(t--)
    {
        s.clear();

        int k;
        cin >> k;
        while(k--)
        {
            string cmd;
            int arg;
            cin >> cmd >> arg;

            process(cmd, arg);
        }

        if (s.empty())
            cout << "EMPTY\n";
        else
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }

    return 0;
}