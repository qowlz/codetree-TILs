#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> arr;
vector<pair<int, int>> pick;

int getDistance(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

int solve(int start)
{
    if (pick.size() == M) 
    {
        int ret = INT_MIN;
        for (int i = 0; i < pick.size(); i++)
        {
            for (int j = i + 1; j < pick.size(); j++)
            {
                auto dist = getDistance(pick[i].first, pick[i].second, pick[j].first, pick[j].second);
                ret = max(ret, dist);
            }
        }

        return ret;
    }

    int ret = INT_MAX;
    for (int i = start; i < N; i++)
    {
        pick.push_back(arr[i]);
        ret = min(ret, solve(i + 1));
        pick.pop_back();
    }

    return ret;
}


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back(make_pair(x, y));    
    }

    cout << solve(0);


    return 0;
}