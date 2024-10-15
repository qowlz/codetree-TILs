#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using T = tuple<long long, int, int>;

// 1 2
// 3 4
// (1,3), (1,4)
// (2, 3), (1, 4)

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr1(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    vector<int> arr2(m, 0);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < m; i++)
        pq.push(make_tuple(arr1[0] + arr2[i], 0, i));
    
    for (int i = 0; i < k - 1; i++)
    {
        int a, b;
        tie(ignore, a, b) = pq.top();
        pq.pop();

        if (a + 1 < n) pq.push(make_tuple(arr1[a + 1] + arr2[b], a + 1, b));
    }

    cout << get<0>(pq.top());
    

    return 0;
}