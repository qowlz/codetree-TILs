#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    s.insert(0);
    int d = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        auto it = s.upper_bound(num);
        if (it != s.end()) 
            d = min(d, *it - num);
        
        it--;
        d = min(d, num - *it);
        
        cout << d << '\n';
        s.insert(num);
    }

    return 0;
}