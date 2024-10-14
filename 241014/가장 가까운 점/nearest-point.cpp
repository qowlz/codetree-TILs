#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
using IntTuple = tuple<int, int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<IntTuple, vector<IntTuple>, greater<IntTuple>> pq;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        pq.push(make_tuple(x + y, x, y));
    }

    while (m--)
    {
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();
        pq.push(make_tuple(d + 4, x + 2, y + 2));
    }

    int ax, ay;
    tie(ignore, ax, ay) = pq.top();
    cout << ax << " " << ay;

    return 0;
}