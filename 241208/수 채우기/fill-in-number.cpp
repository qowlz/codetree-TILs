#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int two = 0;
    int five = 0;
    while (n > 0)
    {
        if (n % 5 == 0)
        {
            five += n / 5;
            n = 0;
        }
        else
        {
            two++;
            n -= 2;
        }
    }

    if (n == 0)
        cout << five + two;
    else
        cout << "-1";
    
    return 0;
}