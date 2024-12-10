#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_T 10000

vector<pair<int, int>> arr;

int getLeftTime(int idx)
{
    return arr[idx].first;
}

int getScore(int idx)
{
    return arr[idx].second;
}

int main() {
    int n;
    cin >> n;

    arr.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
    {
        int leftTime, score;
        cin >> score >> leftTime;
        arr[i] = {leftTime, score};
    }

    sort(arr.begin(), arr.end());

    priority_queue<int> pq;
    int bombIdx = n - 1;
    int ans = 0;
    for (int i = MAX_T; i >= 1; i--)
    {
        while (bombIdx >= 0 && getLeftTime(bombIdx) >= i)
        {
            pq.push(getScore(bombIdx--));
        }

        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}