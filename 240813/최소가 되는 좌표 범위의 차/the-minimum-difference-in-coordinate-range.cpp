#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

int N, D;

pair<int, int> minP {-1, INT_MAX};
pair<int, int> maxP {-1, INT_MIN};
stack<pair<int, int>> minStack;
stack<pair<int, int>> maxStack;

void setMinY(int idx, int value)
{
    if (minP.second < value) return;

    minStack.push(minP);
    minP = {idx, value};
}

void setMaxY(int idx, int value)
{
    if (maxP.second > value) return;

    maxStack.push(maxP);
    maxP = {idx, value};
}

int getDiffY()
{
    if (minP.second == INT_MAX || maxP.second == INT_MIN) return 0;

    return abs(maxP.second - minP.second);
}


pair<int, int> getPrevMin(int i, int j)
{
    while (!minStack.empty())
    {
        auto p = minStack.top();
        minStack.pop();
        if (p.first < i || p.first > j) continue;

        return p;
    }

    return {-1, INT_MAX};
}

pair<int, int> getPrevMax(int i, int j)
{
    while (!maxStack.empty())
    {
        auto p = maxStack.top();
        maxStack.pop();
        if (p.first < i || p.first > j) continue;

        return p;
    }

    return {-1, INT_MIN};
}


int main() {
    cin >> N >> D;

    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    sort(arr.begin(), arr.end());

    int j = -1;
    int answer = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        setMinY(i, arr[i].second);
        setMaxY(i, arr[i].second);

        while (j + 1 < N && getDiffY() < D)
        {
            j += 1;
            setMinY(j, arr[j].second);
            setMaxY(j, arr[j].second);
        }

        // cout << "i: " << i << ", j: " << j << endl;
        // cout << "maxY: " << maxP.second << ", minY: " << minP.second << endl;

        if (getDiffY() >= D)
            answer = min(answer, arr[j].first - arr[i].first);

        if (minP.first == i) minP = getPrevMin(i + 1, j);
        if (maxP.first == i) maxP = getPrevMax(i + 1, j);
    }

    if (answer == INT_MAX)
        cout << "-1";
    else
        cout << answer;

    return 0;
}