#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <numeric>
#include <map>
#include "exceptions.hpp"

using namespace std;

namespace calculations {

class rational{
private:
    int numerator, denominator;

public:
    rational();
    rational(int numerator);
    rational(int numerator, int denominator);
    rational(const rational &other);
    rational& operator=(const rational &other);
    ~rational();

    void pretty();

    int get_numerator();
    int get_denominator();

    friend ostream& operator<< (ostream &out, const rational &w);

    friend rational operator+(const rational &a, const rational &b);
    friend rational operator-(const rational &a, const rational &b);
    friend rational operator*(const rational &a, const rational &b);
    friend rational operator/(const rational &a, const rational &b);
    rational& operator+=(const rational &other);
    rational& operator-=(const rational &other);
    rational& operator*=(const rational &other);
    rational& operator/=(const rational &other);

    rational operator-() const;
    rational operator!() const;
    operator double() const;
    explicit operator int() const;
    
};

}

#endif