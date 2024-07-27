#include <iostream>
#include <unordered_map>
using namespace std;

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

    int answer = 0;
    for (const auto& item : m)
    {
        long long sub = k - item.first;
        cout << "key: " << item.first << ", sub: " << sub << endl;
        if (m[sub])
        {
            cout << "calc: " << item.second * m[sub] << endl;
            answer += item.second * m[sub];
        }
    }

    cout << answer / 2;

    return 0;
}