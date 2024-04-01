#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> cost;
vector<int> pick;
vector<bool> visit;

int solve(int acc)
{
    if (pick.size() >= N - 1)
        return acc + cost[pick.back()][0];

    int current = pick.size() > 0 ? pick.back() : 0;
    int ret = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (visit[i] || !cost[current][i]) continue;

        pick.push_back(i); 
        visit[i] = true;
        ret = min(ret, solve(acc + cost[current][i]));
        pick.pop_back();
        visit[i] = false;
    }

    return ret;
}

int main() {
    cin >> N;
    
    cost.assign(N, vector<int>(N, 0));
    visit.assign(N, false);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    visit[0] = true;
    cout << solve(0);

    return 0;
}