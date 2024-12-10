#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int score, limit;
        cin >> score >> limit;
        arr[i] = {limit, score};
    }

    sort(arr.begin(), arr.end(), cmp);

    int timePassed = 0;
    int ans = 0;
    for (auto& elem : arr)
    {
        int timeLeft, score;
        tie(timeLeft, score) = elem;
        
        if (timeLeft - timePassed <= 0) continue;
        
        ans += score;
        timePassed++;
    }

    cout << ans;

    return 0;
}