#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    clog<< "Enter the lengths of the sides of the triangle:\n";
    double a, b, c;
    cin>> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    // a <= b <= c
    if(a <= 0) {
        clog<< "Error: Values must be positive!\n";
    }
    else if(a + b <= c) {
        clog<< "Error: Incorrect values (" << a << " + " << b << " <= " << c << ")!\n";
    }
    else {
        double s = (a+b+c)/2.0;
        cout<< fixed << setprecision(3);
        cout<< a + b + c << '\n';
        cout<< sqrt(s*(s-a)*(s-b)*(s-c)) << '\n';
    }

    

    

    return 0;
}