#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    const int MAX = 1000 * 1000 + 1;

    int totalTime = 0;
    vector<int> a(MAX, 0);
    for (int i = 0; i < n; i++)
    {
        int v, t;
        cin >> v >> t;
        for (int j = 0; j < t; j++)
        {
            a[totalTime + 1] = a[totalTime] + v;
            totalTime++;
        }
    }

    totalTime = 0;
    vector<int> b(MAX, 0);
    for (int i = 0; i < m; i++)
    {
        int v, t;
        cin >> v >> t;
        for (int j = 0; j < t; j++)
        {
            b[totalTime + 1] = b[totalTime] + v;
            totalTime++;
        }
    }

    char prev = '\0';
    int answer = 0;
    for (int i = 1; i <= totalTime; i++)
    {
        char current = a[i] == b[i] ? '\0' : (a[i] > b[i] ? 'a' : 'b');
        if ((prev == 'a' && current == 'b') || (prev == 'b' && current == 'a')) answer++;

        prev = a[i] == b[i] ? prev : (a[i] > b[i] ? 'a' : 'b');
    }

    cout << answer;

    return 0;
}