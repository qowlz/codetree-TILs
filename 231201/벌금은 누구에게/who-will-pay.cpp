#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> students(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (++students[num] >= k)
        {
            cout << num;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}