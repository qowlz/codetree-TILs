#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map[num]++;
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << map[num] << ' ';
    }
    
    

    return 0;
}