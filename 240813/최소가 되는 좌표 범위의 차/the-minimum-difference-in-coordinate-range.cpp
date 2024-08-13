#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, D;

int getDiffY(int minY, int maxY)
{
    if (minY == INT_MAX || maxY == INT_MIN) return 0;

    return abs(maxY - minY);
}

void updateMinY(int test, int& minY, int& prev)
{
    if (minY <= test) return;

    prev = minY;
    minY = test;
}

void updateMaxY(int test, int& maxY, int& prev)
{
    if (maxY >= test) return;

    prev = maxY;
    maxY = test;
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
    int minY = INT_MAX;
    int prevMin = INT_MAX;
    int maxY = INT_MIN;
    int prevMax = INT_MIN;
    int answer = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        while (j + 1 < N && getDiffY(minY, maxY) < D)
        {
            j += 1;
            updateMinY(arr[j].second, minY, prevMin);
            updateMaxY(arr[j].second, maxY, prevMax);
        }

        if (getDiffY(minY, maxY) >= D)
            answer = min(answer, arr[j].first - arr[i].first);


        minY = prevMin;
        maxY = prevMax;
    }

    if (answer == INT_MAX)
        cout << "-1";
    else
        cout << answer;

    return 0;
}