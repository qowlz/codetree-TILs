#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> pos;
vector<int> turn;
int turnCount = 0, score = 0;
int ans = 0;

void movePawn(int x, int d)
{
    pos[x] += d;
}

void moveForward(int x, int d)
{
    int prev = pos[x];
    movePawn(x, d);

    if (prev < m && pos[x] >= m) score++;
}

void moveBackward(int x, int d)
{
    int prev = pos[x];
    movePawn(x, -d);

    if (prev >= m && pos[x] < m) score--;
}

void solve()
{
    if (turnCount == n)
    {
        ans = max(ans, score);
        return;
    }
    

    for (int i = 1; i <= k; i++)
    {
        moveForward(i, turn[turnCount]);
        turnCount++;

        solve();

        turnCount--;
        moveBackward(i, turn[turnCount]);
    }
}

int main() {
    cin >> n >> m >> k;

    turn.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> turn[i];

    pos.assign(k + 1, 1);
    solve();

    cout << ans;

    return 0;
}