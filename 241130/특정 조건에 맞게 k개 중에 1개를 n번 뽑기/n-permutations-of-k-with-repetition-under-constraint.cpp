#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> picked;

void pick()
{
    if (picked.size() == n)
    {
        for (auto& item : picked)
        {
            cout << item << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= k; i++)
    {
        if (picked.size() >= 2 && i == picked[picked.size() - 1] && i == picked[picked.size() - 2])
            continue;

        picked.push_back(i);
        pick();
        picked.pop_back();
    }
}

int main() {
    cin >> k >> n;
    pick();

    return 0;
}