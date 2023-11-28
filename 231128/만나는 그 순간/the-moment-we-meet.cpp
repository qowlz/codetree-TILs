#include <iostream>
#include <string>
#include <vector>

using namespace std;

void route(vector<int>& arr, int n)
{
    int current = 0;
    int second = 0;

    for (int i = 0; i < n; i++)
    {
        char dir; int dist;
        cin >> dir >> dist;

        int sign = dir == 'L' ? -1 : 1;
        for (int j = 0; j < dist; j++)
        {
            current += sign;
            arr[second++] = current;
        }
    }

}

int main() {
    const int MAX = 1000 * 1000 + 1;

    int n, m;
    cin >> n >> m;

    int currentA = 0;
    int second = 0;
    vector<int> routeA(MAX, 0);
    route(routeA, n);
    
    vector<int> routeB(MAX, 0);
    route(routeB, m);

    int answer = -2;
    for (int i = 0; i < MAX; i++)
    {
        if (routeA[i] == routeB[i])
        {
            answer = i;
            break;
        }
    }

    cout << answer + 1;

    return 0;
}