#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int lower(int x)
{
    int left = 0, right = n - 1;
    int minIdx = n;
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
    int left = 0, right = n - 1;
    int minIdx = n;
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

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while(m--)
    {
        int num;
        cin >> num;
        cout << upper(num) - lower(num) << '\n';
    }

    return 0;
}