#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << '\n';
    }


    return 0;
}