#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n;
vector<int> arr;
vector<int> v;
int slow_idx;


bool isPossible(double t)
{
    double l = max((double)0, (double)arr[slow_idx] - t * v[slow_idx]);
    double r = min((double)1e9, (double)arr[slow_idx] + t * v[slow_idx]);

    double l_best = 0;
    double r_best = 0;
    for (int i = 0; i < n; i++)
    {
        l_best = max(l_best, abs(l - arr[i]) / (double)v[i]);
        r_best = max(r_best, abs(r - arr[i]) / (double)v[i]);
    }
    
    double best = min(l_best, r_best);
    return best <= t;
}


int main() {
    cout << fixed;
    cout.precision(4);

    cin >> n;
    if(n == 1)
    {
        cout << "0.0000";
        return 0;
    }

    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    

    slow_idx = 0;
    int slow_v = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] <= slow_v)
        {
            slow_idx = v[i] == slow_v ? max(slow_idx, i) : i;
            slow_v = v[i];
        }
    }

    double left = 0, right = 1e9;
    double ans = right;
    while (left <= right)
    {
        double mid = (left + right) / 2;
        if (isPossible(mid))
        {
            right = mid - 0.00001;
            ans = min(ans, mid);
        }
        else
            left = mid + 0.00001;
    }

    cout << ans;

    return 0;
}