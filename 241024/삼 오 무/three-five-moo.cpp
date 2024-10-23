#include <iostream>
using namespace std;

int getThree(long long num)
{
    int ret = 0;
    int i = 1;
    while (3 * i <= num)
    {
        ret++;
        i++;
    }

    return ret;
}

int getFive(long long num)
{
    int ret = 0;
    int i = 1;
    while (5 * i <= num)
    {
        ret++;
        i++;
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    
    long long left = 1, right = 200000000;
    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        
        long long order = mid - getThree(mid) - getFive(mid);
        if (order == n)
        {
            ans = mid;
            break;
        }

        if (order > n)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}