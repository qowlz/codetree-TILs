#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr(n, 0);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        m[arr[i]]++;
    }
    
    float answer = 0;
    for (int k = 1; k <= n - 2; k++)
    {
        sum -= arr[k - 1];

        m[arr[k - 1]]--;
        if (m[arr[k - 1]] <= 0) m.erase(arr[k - 1]);

        int small = m.begin()->first;
        float check = (sum - small) / (float)(n - k - 1);
        answer = max(answer, check);
    }

    cout << std::fixed << setprecision(2) << answer;

    return 0;
}