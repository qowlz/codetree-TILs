#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    auto it = s.rbegin();
    for (int i = 0; i < k; i++)
    {
        cout << *it << ' ';
        it++;
    }

    return 0;
}