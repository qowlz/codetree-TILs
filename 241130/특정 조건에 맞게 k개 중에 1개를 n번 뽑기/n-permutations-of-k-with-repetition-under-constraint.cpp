#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> picked;

bool satisfy()
{
    unordered_map<int, int> m;
    for (auto& elem : picked)
    {
        if (++m[elem] == 3) return false;
    }

    return true;
}

void pick()
{
    if (picked.size() == n)
    {
        if (satisfy())
        {
            for (auto& item : picked)
            {
                cout << item << ' ';
            }
            cout << '\n';
        }

        return;
    }

    for (int i = 1; i <= k; i++)
    {
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