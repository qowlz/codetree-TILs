#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, d;
vector<pair<int, int>> points;
map<int, int> m;

int getDiff()
{
    if (m.empty()) return 0;

    return abs(m.rbegin()->first - m.begin()->first);
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    sort(points.begin(), points.end());

    int j = -1;
    int ans = 1e7;
    for (int i = 0; i < n; i++)
    {
        while(j + 1 < n && getDiff() < d)
        {
            m[points[++j].second]++;
        }

        if (getDiff() >= d) 
            ans = min(ans, points[j].first - points[i].first);

        if (--m[points[i].second] <= 0)
            m.erase(points[i].second);
    }

    if (ans == 1e7)
        cout << "-1";
    else
        cout << ans;

    return 0;
}