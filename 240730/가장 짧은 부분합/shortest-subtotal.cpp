#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    // 2 5
    // 5 1
    
    int answer = INT_MAX;
    int i, j = 0;
    int sum = 0;
    while (i < n || j < n)
    {
        if (sum < s && j < n)
            sum += arr[j++];
        else if (i < n)
            sum -= arr[i++];
        
        if (sum >= s)
        {
            answer = min(answer, j - i);
        }
    }

    // 3 5
    // 5 1 6
    // 

    cout << (answer == INT_MAX ? -1 : answer);

    return 0;
}