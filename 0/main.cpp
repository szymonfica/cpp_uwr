#include <iostream>
#include <iomanip>

using namespace std;

#define BOOST ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int main() {
    BOOST

    clog<< "Enter the lengths of the sides of the triangle:\n";
    double a, b, c;
    cin>> a >> b >> c;
    if(a == max(a, max(b, c))) swap(a, c);
    if(b == max(a, max(b, c))) swap(b, c);
    if(b < a) swap(a, b);
    if(a <= 0) {
        clog<< "Error: Values must be positive!\n";
    }
    else if(a + b <= c) {
        clog<< "Error: Incorrect values (" << a << " + " << b << " <= " << c << ")!\n";
    }
    else {
        double s = (a+b+c)/2.0;
        cout<< fixed << setprecision(3) << "Circumference = " << a + b + c << '\n';
        cout<< fixed << setprecision(3) << "Area = " << sqrt(s*(s-a)*(s-b)*(s-c)) << '\n';
    }

    

    

    return 0;
}