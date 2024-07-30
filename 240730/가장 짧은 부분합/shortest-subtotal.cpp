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
    
    int answer = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        int j = i + 1;
        while (j < n)
        {
            sum += arr[j];
            if (sum > s)
            {
                answer = min(answer, j - i + 1);
                break;
            }
            else
            {
                j++;
            }
        }
    }

    cout << (answer == INT_MAX ? -1 : answer);

    return 0;
}