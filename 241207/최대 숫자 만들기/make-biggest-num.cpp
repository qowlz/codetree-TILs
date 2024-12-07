#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
    string ab = a + b;
    string ba = b + a;

    for (int i = 0; i < ab.length(); i++)
    {
        if (ab[i] == ba[i]) continue;

        return ab[i] > ba[i];
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