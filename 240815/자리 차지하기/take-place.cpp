#include <iostream>
#include <set>
using namespace std;

// 2 2 2
    // 1 2 3 4
    // 1 3 4
    // 3 4 

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i = 1; i <= m; i++)
        s.insert(i);
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        auto it = s.upper_bound(num);
        if (it == s.begin()) break;
        else s.erase(*(--it));

        answer++;
    }

    cout << answer;

    return 0;
}