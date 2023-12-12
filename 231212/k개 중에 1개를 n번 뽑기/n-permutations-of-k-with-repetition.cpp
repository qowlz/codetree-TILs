#include <iostream>
#include <vector>

using namespace std;

int N, K;

void dfs(vector<int>& nums)
{
    if (nums.size() == N) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= K; i++)
    {
        nums.push_back(i);
        dfs(nums);
        nums.pop_back();
    }
}

int main() {
    cin >> K >> N;

    vector<int> arr(0);
    dfs(arr);

    return 0;
}