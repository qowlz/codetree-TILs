#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, int>& a, pair<long long, int>& b)
{
    if (a.second == b.second) 
        return a.first > b.first;
    else
        return a.second > b.second;
}

int main() {

    int n, k;
    cin >> n >> k;

    unordered_map<long long, int> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }

    vector<pair<long long, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < k; i++)
    {
        cout << v[i].first << ' ';
    }
    
    return 0;
}