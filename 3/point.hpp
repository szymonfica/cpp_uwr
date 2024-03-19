#ifndef POINT_HPP
#define POINT_HPP

#include "structs.hpp"

class point {
private:
    double x, y;

public:
    point(double x, double y);
    point(const point &p);
    point();

    double getX();
    double getY();
    void setX(double x);
    void setY(double y);

    void translation(vec v);
    void rotate(point p, double angle);
    void cen_sym(point p);
    void sym_X();
    void sym_Y();
    void sym_line(linear l);
    
};

#endif