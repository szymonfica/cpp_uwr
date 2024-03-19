#include "structs.hpp"

vec::vec(double x, double y) {
    this->x = x;
    this->y = y;
}
vec::vec() {
    this->x = 0;
    this->y = 0;
}
vec::~vec() {
    this->x = 0;
    this->y = 0;
}
double vec::getX() { return x; }
double vec::getY() { return y; }
void vec::setX(double x) { this->x = x; }
void vec::setY(double y) { this->y = y; }

linear::linear(double a, double b, double c) {
    try {
        if(a == 0 && b == 0) {
            throw invalid_argument("Error: A == B == 0.");
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
        }
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }
}
linear::~linear() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
}
double linear::getA() { return a; }
double linear::getB() { return b; }
double linear::getC() { return c; }
void linear::setA(double a) { this->a = a; }
void linear::setB(double b) { this->b = b; }
void linear::setC(double c) { this->c = c; }