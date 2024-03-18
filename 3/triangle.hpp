#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "segment.hpp"

class triangle {
private:
    point a, b, c;

public:
    triangle(point a, point b, point c);
    point get_A();
    point get_B();
    point get_C();
    void set_A(point p);
    void set_B(point p);
    void set_C(point p);

    void translation(vec v);
    void rotate(point p, double angle);
    void cen_sym(point p);
    void sym_X();
    void sym_Y();
    void sym_line(linear l);

    double perimeter();
    double area();
    bool point_inside_triangle(point d);
};

bool parallel(segment a, segment b);
bool perpendicular(segment a, segment b);
bool intersect(segment a, segment b);
bool disjoint(triangle a, triangle b);
bool contains(triangle a, triangle b);

#endif