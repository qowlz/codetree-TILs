#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
    size_t loop = max(a.length(), b.length());
    for (size_t i = 0; i < loop; i++)
    {
        size_t idxA = min(i, a.length() - 1);
        size_t idxB = min(i, b.length() - 1);

        if (a[idxA] == b[idxB]) continue;
        else return a[idxA] > b[idxB];
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i];

    return 0;
}