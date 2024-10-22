#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int lower(int x)
{
    int left = 1, right = n;
    int minIdx = n + 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] >= x)
        {
            right = mid - 1;
            minIdx = min(minIdx, mid);
        }
        else
            left = mid + 1;
    }

    return minIdx;
}

int upper(int x)
{
    int left = 1, right = n;
    int minIdx = n + 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > x)
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

    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    while(m--)
    {
        int x;
        cin >> x;

        int l = lower(x);
        int u = upper(x);
        cout << (u - l == 0 ? -1 : l) << '\n';
    }

    return 0;
}