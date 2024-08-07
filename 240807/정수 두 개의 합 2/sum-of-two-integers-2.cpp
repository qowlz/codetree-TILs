#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 소팅으로 풀면 안되나?
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n - 1;
    int answer = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] <= k)
        {
            answer += (j - i);
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << answer;

    return 0;
}