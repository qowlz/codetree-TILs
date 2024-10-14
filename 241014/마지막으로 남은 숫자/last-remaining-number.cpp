#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        if (a == b) continue;

        pq.push(abs(a - b));
    }

    if (pq.empty()) cout << "-1";
    else cout << pq.top();

    return 0;
}