#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> b(m, 0);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j < m && a[i] == b[j]) j++;
    }

    cout << (j == m ? "Yes" : "No");

    return 0;
}