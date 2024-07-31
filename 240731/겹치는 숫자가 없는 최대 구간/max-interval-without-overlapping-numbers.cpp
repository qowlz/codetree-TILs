#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX_NUM 100000

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int answer = 0;
    int j = -1;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < n && !count[arr[j + 1]])
        {
            j += 1;
            count[arr[j]] += 1;
        }

        // cout << "i: " << i << ", j: " << j << endl;
        answer = max(answer, j - i + 1);

        count[arr[i]] -= 1;
    }

    cout << answer;



    return 0;
}