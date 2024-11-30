#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> picked;

bool satisfy()
{
    for (int i = 0; i < picked.size(); i++)
    {
        if (i + 2 >= picked.size()) continue;

        if (picked[i] == picked[i + 1] && picked[i + 1] == picked[i + 2])
            return false;
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