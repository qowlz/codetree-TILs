#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> lines;
vector<pair<int, int>> picked;

bool isOverlap(int x1, int x2, int xx1, int xx2)
{
    return (xx1 >= x1 && xx1 <= x2) || (xx2 >= x1 && xx2 <= x2);
}

bool isOverlapInPicks(int x1, int x2)
{
    for (int i = 0; i < picked.size(); i++)
    {
        auto p = picked[i];
        if (isOverlap(p.first, p.second, x1, x2)) return true;
    }

    return false;
}

int solve(int idx, int acc)
{
    if (idx >= N) return acc;

    int ret = acc;
    for (int i = idx + 1; i < lines.size(); i++)
    {
        if (isOverlapInPicks(lines[i].first, lines[i].second)) continue;

        picked.push_back(make_pair(lines[i].first, lines[i].second));
        ret = max(ret, solve(i, acc + 1));
        picked.pop_back();
    }

    return ret;
}


int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, x2));
    }

    cout << solve(-1, 0);

    return 0;
}