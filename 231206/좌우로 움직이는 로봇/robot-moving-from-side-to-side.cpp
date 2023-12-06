#include <iostream>
#include <vector>

using namespace std;

int clamp(int v, int min, int max)
{
    if (v < min) return min;
    else if (v > max) return max;

    return v;
}

int main() {
    int n, m;
    cin >> n >> m;

    int totalTime = 0;
    vector<int> posA(1, 0);
    for (int i = 0; i < n; i++)
    {
        int t; char d;
        cin >> t >> d;
        
        int dir = d == 'L' ? -1 : 1;
        for (int j = 0; j < t; j++)
        {
            posA.push_back(posA[totalTime++] + dir);
        }
    }

    totalTime = 0;
    vector<int> posB(1, 0);
    for (int i = 0; i < m; i++)
    {
        int t; char d;
        cin >> t >> d;
        
        int dir = d == 'L' ? -1 : 1;
        for (int j = 0; j < t; j++)
        {
            posB.push_back(posB[totalTime++] + dir);
        }
    }

    int answer = 0;
    for (int i = 2; i <= totalTime; i++)
    {
        int lastA = clamp(i - 1, 0, posA.size() - 1);
        int lastB = clamp(i - 1, 0, posB.size() - 1);
        int curA = clamp(i, 0, posA.size() - 1);
        int curB = clamp(i, 0, posB.size() - 1);
        if (posA[lastA] != posB[lastB] && posA[curA] == posB[curB]) answer++;
    }

    cout << answer;

    return 0;
}