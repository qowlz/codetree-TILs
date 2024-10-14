#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    
    int n;
    cin >> n;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int e;
            cin >> e;
            pq.push(e);
        }
        else if (cmd == "pop")
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if (cmd == "size")
        {
            cout << pq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << pq.empty() << '\n';
        }
        else if (cmd == "top")
        {
            cout << pq.top() << '\n';
        }
    }

    return 0;
}