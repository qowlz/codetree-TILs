#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    float answer = 0;
    for (int k = 1; k <= n - 2; k++)
    {
        sum -= arr[k - 1];

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = k; i < n; i++)
            pq.push(arr[i]);

        float check = (sum - pq.top()) / (float)(n - k - 1);
        answer = max(answer, check);
    }

    cout << std::fixed << setprecision(2) << answer;

    return 0;
}