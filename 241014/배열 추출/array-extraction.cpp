#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
        else
            pq.push(num);
    }

    return 0;
}