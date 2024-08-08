#include <iostream>
#include <vector>
using namespace std;

const int maxX = 1000000;

int main() {
    int n, k;
    cin >> n >> k;

    int amount, pos;
    vector<int> arr(maxX + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> amount >> pos;
        arr[pos] += amount;
    }

    int answer = 0;
    int sum = 0;
    int j = 0;
    for (int i = 0; i <= maxX; i++)
    {
        while (j <= maxX && (j - i) <= 2 * k)
        {
            sum += arr[j++];
        }

        answer = max(answer, sum);

        sum -= arr[i];
    }

    cout << answer;
    
    return 0;
}