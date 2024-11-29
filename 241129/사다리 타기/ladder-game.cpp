#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <climits>
using namespace std;

#define MAX_H 15

int n, m;

vector<tuple<int, int, int>> lines;
vector<vector<int>> board;
vector<vector<bool>> exclude;
unordered_map<int, int> expect;

vector<int> picked;
int ans = INT_MAX;

bool simulate()
{
    int match = 0;
    for (int i = 1; i <= n; i++)
    {
        int place = i;
        for (int j = 1; j <= 15; j++)
        {
            if (exclude[j][place]) continue;

            if (board[j][place])
                place = board[j][place];
        }

        if (expect[i] == place) match++;
    }

    return match == n;
}

void solve(const int& maxPick, int start)
{
    if (picked.size() == maxPick)
    {
        // cout << "picked: " << endl;
        for (auto& idx : picked)
        {
            int h, from, to;
            tie(h, from, to) = lines[idx];
            // cout << "\tidx: " << idx << endl;
            // cout << "\th: " << h << ", from: " << from << ", to: " << to << endl;
            // cout << "=====================" << endl;

            exclude[h][from] = true;
            exclude[h][to] = true;
        }

        bool match = simulate();

        for (auto& idx : picked)
        {
            int h, from, to;
            tie(h, from, to) = lines[idx];

            exclude[h][from] = false;
            exclude[h][to] = false;
        }

        if (match)
            ans = min(ans, m - maxPick);

        return;
    }

    for (int i = start; i < m; i++)
    {
        picked.push_back(i);
        solve(maxPick, i + 1);
        picked.pop_back();
    }
}


int main() {
    cin >> n >> m;

    board.assign(MAX_H + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[b][a] = a + 1;
        board[b][a + 1] = a;
        lines.push_back(make_tuple(b, a, a + 1));
    }

    // 정답 구해놓기
    for (int i = 1; i <= n; i++)
    {
        int place = i;
        for (int j = 1; j <= 15; j++)
        {
            if (board[j][place]) place = board[j][place];
        }

        expect[i] = place;
    }

    exclude.assign(MAX_H + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= m; i++)
        solve(i, 0);

    cout << ans;

    return 0;
}