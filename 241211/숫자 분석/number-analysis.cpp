#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;

    string numStr = to_string(num);
    int sum = 0;
    for (int i = numStr.length() - 1; i >= 0; i--)
    {
        cout << numStr[i];
        sum += numStr[i] - '0';
    }

    cout << ' ' << sum;

    
    return 0;
}