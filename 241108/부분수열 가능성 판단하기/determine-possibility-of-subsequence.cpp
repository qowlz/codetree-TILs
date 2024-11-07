#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;

int main() {
    cin >> n >> m;

    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    b.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    

    vector<int> L(m, 0);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while(j < n && a[j] != b[i])
            j++;

        L[i] = j++;
    }

    vector<int> R(m, 0);
    j = n - 1;
    for (int i = m - 1; i >= 0; i--)
    {
        while(j >= 0 && a[j] != b[i])
            j--;

        R[i] = j--;
    }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << "L[" << i << "]: " << L[i] << endl;
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << "R[" << i << "]: " << R[i] << endl;
    // }


    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if ((i == 0 && R[1] >= 0) || (i == m - 1 && L[m - 2] < n))
        {
            ans++;
        }
        else if (L[i - 1] < R[i + 1])
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}