#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int answer = 0;
    unordered_map<long long, int> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long sub = k - arr[i] - arr[j];
            if (m[sub]) answer += m[sub];
        }

        m[arr[i]]++;
    }

    cout << answer;

    return 0;
}