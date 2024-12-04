#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr1(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    
    vector<int> arr2(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    unordered_map<int, int> m1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m1[arr1[i] + arr2[j]]++;
        }
    }

    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    unordered_map<int, int> m2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m2[arr1[i] + arr2[j]]++;
        }
    }

    int ans = 0;
    for (auto& it: m1)
    {
        ans += it.second * m2[-it.first];
    }

    cout << ans;

    return 0;
}