#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--)
    {
        int x;
        cin >> x;
        pq.push(x);

        if (pq.size() >= 3)
        {
            vector<int> temp(3, 0);
            long long ans = 1;
            for (int i = 0; i < 3; i++)
            {
                temp[i] = pq.top();
                pq.pop();
                ans *= temp[i];
            }

            cout << ans << '\n';

            for (int i = 2; i >= 0; i--)
                pq.push(temp[i]);
        }
        else
            cout << "-1\n";
    }

    return 0;
}