#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000


int n;
vector<int> arr[MAX_N + 1];
int parent[MAX_N + 1];

void traversal(int x, int prev)
{
    parent[x] = prev;

    for (int i = 0; i < arr[x].size(); i++)
    {
        traversal(arr[x][i], x);
    }
}



int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    traversal(1, -1);

    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}