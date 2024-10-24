#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, t;
vector<int> d;

bool isPossible(int k)
{
    // cout << "k: " << k << endl;
    vector<int> current(k + 1, 0);
    int total = 0;
    int next = 0;
    while (true)
    {
        // 사람들을 무대 위로 채우기
        for (int i = 1; i <= k; i++)
        {
            if (current[i] || next + 1 > n) continue;

            current[i] = d[++next];
        }

        // 종료 조건 체크
        bool allOut = true;
        for (int i = 1; i <= k; i++)
        {
            if (current[i]) allOut = false;
        }

        if (allOut && next + 1 > n) break;

        // 최소 시간 계산
        int min_t = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (current[i]) min_t = min(min_t, current[i]);
            // cout << current[i] << ' ';
        }
        // cout << endl;

        // 시간 정산하기
        total += min_t;
        for (int i = 1; i <= k; i++)
            current[i] = max(0, current[i] - min_t);
    }

    // cout << "total: " << total << endl;

    return total <= t;
}


int main() {
    cin >> n >> t;

    d.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    
    int left = 1, right = 10000; // 10000
    int ans = right;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (isPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}