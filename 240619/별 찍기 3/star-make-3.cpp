#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int middle = n / 2;
    int white = -1;
    int stars = -1;
    for (int i = 0; i < n; i++)
    {
        // print white space
        white = i > middle ? white - 1 : white + 1;
        for (int j = 0; j < white; j++)
            cout << " ";
        
        // print star
        stars = i > middle ? stars - 2 : stars + 2;
        for (int j = 0; j < stars; j++)
            cout << "*";
        
        cout << '\n';
    }


    return 0;
}