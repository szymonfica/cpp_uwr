#include "rational.hpp"

using namespace calculations;

int main() {

    rational a(1, 2);
    rational b(1, 30);
    cout<< "a = " << a << ", b = " << b << '\n';
    rational c = a+b;
    cout<< "a+b = " << c.get_numerator() << "/" << c.get_denominator() << " = " << c << '\n';
    c = a-b;
    cout<< "a-b = " << c.get_numerator() << "/" << c.get_denominator() << " = " << c << '\n';
    c = a*b;
    cout<< "a*b = " << c.get_numerator() << "/" << c.get_denominator() << " = " << c << '\n';
    c = a/b;
    cout<< "a/b = " << c.get_numerator() << "/" << c.get_denominator() << " = " << c << '\n';
    rational d(2359348, 99900);
    double x = d;
    int y = static_cast<int>(d);
    cout<< d << ",  double = " << x << ",  int = " << y << '\n';
    cout<< "-!d = " << -!d << '\n';
    try {
        rational w = rational(1, 0);
    }
    catch(division_by_zero) {
        cerr << "get_denominator == 0 !!" << '\n';
    }
    try {
        rational w1 = rational(1000000, 1);
        rational w2 = rational(1000000, 1);
        rational w = w1 * w2;

    }
    catch(number_out_of_range) {
        cerr << "Number is out of range!" << '\n';
    }
    


    return 0;
}