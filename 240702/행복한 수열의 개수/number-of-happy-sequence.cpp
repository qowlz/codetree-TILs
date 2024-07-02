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
        int maximum = 0;
        int cnt = 1;
        int prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == prev)
            {
                cnt++;
            }
            else
            {
                maximum = max(maximum, cnt);
                cnt = 1;
            }

            prev = arr[i][j];
        }

        maximum = max(maximum, cnt);

        if (maximum >= m)
        {
            answer++;
        }
    }

    // col
    for (int i = 0; i < n; i++)
    {
        int maximum = 0;
        int cnt = 1;
        int prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == prev)
            {
                cnt++;
            }
            else
            {
                maximum = max(maximum, cnt);
                cnt = 1;
            }

            prev = arr[j][i];
        }

        maximum = max(maximum, cnt);

        if (maximum >= m)
        {
            answer++;
        }
    }

    cout << answer;


    return 0;
}