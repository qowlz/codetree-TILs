#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 100000

int n;
vector<pair<int, int>> arr[MAX_N + 1];
vector<bool> visited;
int far_v = 1;
int far_d = 0;

void traversal(int x, int d)
{
    visited[x] = true;
    if (d > far_d)
    {
        far_v = x;
        far_d = d;
    }

    for (int i = 0; i < arr[x].size(); i++)
    {
        int to, w;
        tie(to, w) = arr[x][i];

        if (!visited[to]) traversal(to, d + w);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        arr[s].push_back({e, w});
        arr[e].push_back({s, w});
    }

    visited.assign(n + 1, false);
    traversal(1, 0);

    far_d = 0;
    visited.assign(n + 1, false);
    traversal(far_v, 0);

    cout << far_d;

    return 0;
}