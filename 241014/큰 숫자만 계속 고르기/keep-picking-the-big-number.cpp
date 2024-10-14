#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (m--)
    {
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }

    cout << pq.top();

    return 0;
}