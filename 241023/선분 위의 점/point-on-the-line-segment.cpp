#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> points;

int main()
{
    cin >> n >> m;

    points.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> points[i];

    sort(points.begin(), points.end());

    for (int i = 0; i < m; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        cout << upper_bound(points.begin(), points.end(), x2) - lower_bound(points.begin(), points.end(), x1) << '\n';
    }

    return 0;

}