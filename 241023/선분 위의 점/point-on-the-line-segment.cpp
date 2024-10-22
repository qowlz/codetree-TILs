#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> points;

int lowerBound(int x)
{
    int left = 0, right = n - 1;
    int minIdx = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (points[mid] >= x)
        {
            right = mid - 1;
            minIdx = min(minIdx, mid);
        }
        else
            left = mid + 1;
    }

    return minIdx;
}

int upperBound(int x)
{
    int left = 0, right = n - 1;
    int minIdx = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (points[mid] > x)
        {
            right = mid - 1;
            minIdx = min(minIdx, mid);
        }
        else
            left = mid + 1;
    }

    return minIdx;
}

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
        cout << upperBound(x2) - lowerBound(x1) << '\n';
    }

    return 0;

}