#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<unsigned int> s;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (s.empty())
            {
                cout << "0\n";
                continue;
            }

            cout << *s.begin() << '\n';
            s.erase(s.begin());
        }
        else
            s.insert(num);
    }

    return 0;
}