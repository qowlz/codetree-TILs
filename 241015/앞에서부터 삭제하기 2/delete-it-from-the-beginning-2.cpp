#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = arr[n - 1];
    float answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[n - 1]);
    for (int i = n - 2; i >= 1; i--)
    {
        sum += arr[i];
        pq.push(arr[i]);

        float check = (sum - pq.top()) / (float)(n - i - 1);
        answer = max(answer, check);
    }

    cout << std::fixed << setprecision(2) << answer;

    return 0;
}