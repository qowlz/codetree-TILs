#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> arr;
vector<bool> col;
vector<int> picked;

int solve(int row)
{
    if (picked.size() >= N)
    {
        int minimum = INT_MAX;
        for (int i = 0; i < picked.size(); i++)
            minimum = min(minimum, picked[i]);

        return minimum;
    }

    int ret = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (col[i]) continue;

        picked.push_back(arr[row][i]);
        col[i] = true;
        ret = max(ret, solve(row + 1));
        picked.pop_back();
        col[i] = false;
    }

    return ret;
}

int main() {
    cin >> N;

    col.assign(N, false);
    arr.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    cout << solve(0);

    return 0;
}