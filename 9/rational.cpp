#include "rational.hpp"

namespace calculations {

void rational::pretty() {
    if(this->numerator == 0) {
        this->denominator = 1;
        return;
    }
    int d = gcd(abs(this->numerator), abs(this->denominator));
    this->numerator /= d;
    this->denominator /= d;
    if(this->numerator < 0 && this->denominator < 0) {
        this->numerator = abs(this->numerator);
        this->denominator = abs(this->denominator);
    }
    else if(this->denominator < 0) {
        this->numerator = -1 * this->numerator;
        this->denominator = abs(this->denominator);
    }
}

rational::rational(int numerator, int denominator) {
    if(denominator == 0) {
        throw division_by_zero();
    }
    this->numerator = numerator;
    this->denominator = denominator;
    rational::pretty();
}
rational::rational(int numerator) : rational::rational(numerator, 1) {}
rational::rational() : rational::rational(0, 1) {}
rational::rational(const rational &other)
    : numerator(other.numerator), denominator(other.denominator) { }
rational& rational::operator=(const rational &other) {
    if(this != &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    return *this;
}
rational::~rational() {}

int rational::get_numerator() {
    return this->numerator;
}
int rational::get_denominator() {
    return this->denominator;
}

rational& rational::operator+= (const rational &b){
    if(2147483647-abs(this->numerator) < abs(b.denominator) || 2147483647/this->denominator < b.numerator || 2147483647-abs(this->numerator*b.denominator) < abs(b.numerator*this->denominator) || 2147483647/abs(this->numerator) < abs(b.denominator)) {
        throw number_out_of_range();
    }
    this->numerator = this->numerator*b.denominator + b.numerator*this->denominator;
    this->denominator *= b.denominator;
    this->pretty();
    return *this;
}
rational& rational::operator-= (const rational &b){
    if(2147483647-abs(this->numerator) < (b.denominator) || 2147483647/this->denominator < b.numerator || 2147483647-abs(this->numerator*b.denominator) < abs(b.numerator*this->denominator) || 2147483647/abs(this->numerator) < abs(b.denominator)) {
        throw number_out_of_range();
    }
    this->numerator = this->numerator*b.denominator - b.numerator*this->denominator;
    this->denominator *= b.denominator;
    this->pretty();
    return *this;
}
rational& rational::operator*= (const rational &b){
    if(2147483647/abs(this->numerator) < (b.numerator) || 2147483647/abs(this->denominator) < abs(b.denominator)) {
        throw number_out_of_range();
    }
    this->numerator *= b.numerator;
    this->denominator *= b.denominator;
    this->pretty();
    return *this;
}
rational& rational::operator/= (const rational &b){
    if(b.numerator == 0) {
        throw division_by_zero();
    }
    if(2147483647/abs(this->numerator) < (b.denominator) || 2147483647/abs(this->denominator) < abs(b.numerator)) {
        throw number_out_of_range();
    }
    this->numerator *= b.denominator;
    this->denominator *= b.numerator;
    this->pretty();
    return *this;
}
rational operator+(const rational &a, const rational &b) {
    rational result(a.numerator, a.denominator);
    result += b;
    return result;
}
rational operator-(const rational &a, const rational &b) {
    rational result(a.numerator, a.denominator);
    result -= b;
    return result;
}
rational operator*(const rational &a, const rational &b) {
    rational result(a.numerator, a.denominator);
    result *= b;
    return result;
}
rational operator/(const rational &a, const rational &b) {
    rational result(a.numerator, a.denominator);
    result /= b;
    return result;
}
rational rational::operator-() const {
    return rational(-1 * this->numerator, this->denominator);
}
rational rational::operator!() const {
    if(this->numerator == 0) {
        throw division_by_zero();
    }
    return rational(this->denominator, this->numerator);
}
rational::operator double() const {
    return static_cast<double>(this->numerator) / this->denominator;
}
rational::operator int() const {
    return round(static_cast<double>(this->numerator) / this->denominator);
}
ostream& operator<< (ostream &out, const rational &w){
    int num = abs(w.numerator);
    int den = w.denominator;
    if(w.numerator < 0) {
        out<< "-";
    }
    int integer_part = num / den;
    out << integer_part;
    num = num % den * 10;
    if (num != 0) {
        out << ".";
    }
    map<int, int> pos_map;
    string fractional_part;
    int pos = 0;
    int limit = 50;
    while (num != 0) {
        if (pos_map.find(num) != pos_map.end()) {
            fractional_part.insert(pos_map[num], "(");
            fractional_part.push_back(')');
            break;
        }
        pos_map[num] = pos++;
        int digit = num / den;
        fractional_part.push_back('0' + digit);
        num = (num % den) * 10;
        limit--;
        if(limit < 0) {
            break;
        }
    }

    out << fractional_part;
    return out;
}

}