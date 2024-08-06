#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int sum = 0;
    int j = 0;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && sum < m)
            sum += arr[j++];

        if (sum == m) answer++;

        sum -= arr[i];
    }

    cout << answer;

    return 0;
}