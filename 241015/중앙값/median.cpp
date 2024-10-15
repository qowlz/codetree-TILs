#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;

        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        for (int i = 1; i <= m; i++)
        {
            int n;
            cin >> n;

            if (i % 2 == 1)
                left.push(n);
            else
                right.push(n);
            
            bool isEmpty = left.empty() || right.empty();
            if (!isEmpty && left.top() > right.top())
            {
                int lt = left.top();
                int rt = right.top();
                
                left.pop();
                right.pop();

                left.push(rt);
                right.push(lt);
            }

            if (i % 2 == 1) cout << left.top() << ' ';
        }

        cout << '\n';
    }

    return 0;
}