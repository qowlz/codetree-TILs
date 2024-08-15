#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
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

    int answer = INT_MAX;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        int add = *it + m;
        auto add_it = s.lower_bound(add);
        if (add_it != s.end()) answer = min(answer, abs(*add_it - *it));

        int sub = *it - m;
        auto sub_it = s.lower_bound(sub);
        if (sub_it != s.begin()) answer = min(answer, abs(*(--sub_it) - *it));
    }

    if (answer == INT_MAX)
        cout << "-1";
    else
        cout << answer;

    

    return 0;
}