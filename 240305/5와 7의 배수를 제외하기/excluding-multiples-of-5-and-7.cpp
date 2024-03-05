#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num % 5 == 0 || num %7 == 0) continue;

        sum += num;
        cnt++;
    }

    cout << sum << '\n';
    cout << std::fixed << std::setprecision(1) << sum / (float)cnt;
    
    return 0;
}