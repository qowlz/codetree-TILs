#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // -3 -2 -1 0 1
    int i = 0;
    int j = n - 1;
    int answer = INT_MAX;
    while (i < j)
    {
        int add = arr[i] + arr[j];
        answer = min(answer, abs(add));
        
        if (add > 0)
            j--;
        else
            i++;
    }

    cout << answer;


    return 0;
}