#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;

int main() {
    cin >> n >> m;

    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    b.assign(m + 1, 0);
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    vector<int> L(m + 2, -1);
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        while(j <= n && a[j] != b[i])
            j++;

        L[i] = j++;
    }

    vector<int> R(m + 2, n + 1);
    j = n;
    for (int i = m; i >= 1; i--)
    {
        while(j >= 0 && a[j] != b[i])
            j--;

        R[i] = j--;
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     cout << "L[" << i << "]: " << L[i] << endl;
    // }

    // for (int i = 1; i <= m; i++)
    // {
    //     cout << "R[" << i << "]: " << R[i] << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (L[i - 1] < R[i + 1])
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}