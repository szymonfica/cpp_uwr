#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

struct vec {
private:
    double x, y;
public:
    vec(double x, double y);
    vec();
    ~vec();

    double getX();
    double getY();
    void setX(double x);
    void setY(double y);

};

struct linear {
private:
    double a, b, c;
public:
    linear(double a, double b, double c);
    ~linear();

    double getA();
    double getB();
    double getC();
    void setA(double a);
    void setB(double b);
    void setC(double c);

};


#endif