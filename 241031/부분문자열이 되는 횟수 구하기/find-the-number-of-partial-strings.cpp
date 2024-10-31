#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string a, b;
vector<int> arr;

void findSubStr(unordered_set<int>& s, unordered_set<int> removed)
{
    int idx = 0;
    for (int j = 0; j < a.size(); j++)
    {
        if (removed.find(j) != removed.end()) continue;

        if (idx < b.size() && b[idx] == a[j])
        {
            s.insert(j);
            idx++;
        }
    }
}

bool isPossible(int mid)
{
}


int main() {
    cin >> a >> b;
    
    arr.assign(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> arr[i];
        arr[i] -= 1;
    }

    unordered_set<int> removed;
    unordered_set<int> s;
    findSubStr(s, removed);
    if (s.size() != b.size())
    {
        cout << "0";
        return 0;
    }

    int cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        removed.insert(arr[i]);
        if (a.size() - i < b.size()) break;

        if (s.find(arr[i]) != s.end())
        {
            s.clear();
            findSubStr(s, removed);

            if (s.size() != b.size()) break;
        }

        cnt++;
    }

    cout << cnt;

    return 0;
}