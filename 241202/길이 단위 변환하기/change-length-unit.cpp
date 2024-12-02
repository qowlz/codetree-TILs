#include <iostream>
using namespace std;

int main() {
    double ft2cm = 30.48;
    int mi2cm = 160934;

    cout << fixed;
    cout.precision(1);
    cout << "9.2ft = " << 9.2 * ft2cm << "cm\n";
    cout << "1.3mi = " << 1.3 * mi2cm << "cm";

    return 0;
}