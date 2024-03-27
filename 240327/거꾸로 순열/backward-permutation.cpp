#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> pick;
vector<bool> visit;

void solve()
{
    if (pick.size() >= N)
    {
        for (int i = 0; i < pick.size(); i++)
            cout << pick[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = N; i >= 1; i--)
    {
        if (visit[i]) continue;

        pick.push_back(i);
        visit[i] = true;
        solve();
        visit[i] = false;
        pick.pop_back();
    }

}

int main() {
    cin >> N;

    visit.assign(N + 1, false);
    solve();

    return 0;
}