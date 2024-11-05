#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, d;
vector<pair<int, int>> points;
map<int, int> m;

bool satisfy(int j)
{
    if (m.empty()) return true;

    int maxY = max(points[j].second, m.rbegin()->first);
    int minY = min(points[j].second, m.begin()->first);
    return abs(maxY - minY) >= d;
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
        while(j + 1 < n && satisfy(j + 1))
        {
            m[points[++j].second]++;

            if (m.size() > 1)
            {
                ans = min(ans, points[j].first - points[i].first);
                // cout << "i: " << i << ", j: " << j << endl;
            }
        }

        if (--m[points[i].second] <= 0)
            m.erase(points[i].second);
    }

    if (ans == 1e7)
        cout << "-1";
    else
        cout << ans;



    return 0;
}