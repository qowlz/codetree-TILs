#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    
    vector<int> checks(m, 0);
    for (int i = 0; i < m; i++)
        cin >> checks[i];
    
    for (const auto& chk : checks)
    {
        auto it = s.lower_bound(chk);
        if (it == s.end())
            cout << "-1\n";
        else
            cout << *it << "\n";
    }
    


    return 0;
}