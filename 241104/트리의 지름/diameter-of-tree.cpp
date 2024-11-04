#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

int n;
vector<pair<int, int>> arr[MAX_N + 1];
int far_v = 0;
int far_d = 0;

void traversal(int x, int d)
{
    if (d > far_d)
    {
        far_v = x;
        far_d = d;
    }

    for (int i = 0; i < arr[x].size(); i++)
    {
        traversal(arr[x][i].first, d + arr[x][i].second);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        arr[s].push_back({e, w});
    }

    traversal(1, 0);

    far_d = 0;
    traversal(far_v, 0);

    cout << far_d;

    return 0;
}