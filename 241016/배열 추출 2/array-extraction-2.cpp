#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<long long, long long>;

int main() {
    int n;
    cin >> n;

    priority_queue<P, vector<P>, greater<P>> pq;
    while(n--)
    {
        long long x;
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
                continue;
            }

            cout << pq.top().second << '\n';
            pq.pop();
        }
        else
            pq.push(make_pair(abs(x), x));
    }

    return 0;
}