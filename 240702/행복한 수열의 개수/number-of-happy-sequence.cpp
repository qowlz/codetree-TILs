#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int answer = 0;

    // row
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == prev) cnt++;

            prev = arr[i][j];
        }

        if (cnt >= m)
        {
            answer++;
            // cout << "11" << endl;
        }
    }

    // col
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == prev) cnt++;

            prev = arr[j][i];
        }

        if (cnt >= m)
        {
            answer++;
            // cout << "22" << endl;
        }
    }

    cout << answer;


    return 0;
}