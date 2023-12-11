#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int total_time = 0;
    vector<int> pos_a(1, 0);
    for (int i = 0; i < n; i++)
    {
        int v, t;
        cin >> v >> t;
        
        for (int j = 0; j < t; j++) pos_a.push_back(pos_a[total_time++] + v);
    }

    total_time = 0;
    vector<int> pos_b(1, 0);
    for (int i = 0; i < m; i++)
    {
        int v, t;
        cin >> v >> t;
        
        for (int j = 0; j < t; j++) pos_b.push_back(pos_b[total_time++] + v);
    }

    int answer = 0;
    string honor = "";
    for (int i = 1; i <= total_time; i++)
    {
        string lead = pos_a[i] == pos_b[i] ? "AB" : (pos_a[i] > pos_b[i] ? "A" : "B");
        if (honor != lead)
        {
            honor = lead;
            answer++;
        }
    }

    cout << answer;

    return 0;
}