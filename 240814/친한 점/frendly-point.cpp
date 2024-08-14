#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        auto it = s.lower_bound({x, y});
        if (it == s.end())
            cout << "-1 -1\n";
        else
            cout << (*it).first << ' ' << (*it).second << '\n';
    }


    return 0;
}