#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "point.hpp"
#include "structs.hpp"

class segment {
private:
    point a;
    point b;

public:
    segment(point a, point b);
    segment(const segment& s);

    point get_A();
    point get_B();
    void set_A(point p);
    void set_B(point p);

    void translation(vec v);
    void rotate(point p, double angle);
    void cen_sym(point p);
    void sym_X();
    void sym_Y();
    void sym_line(linear l);

    double length();
    bool point_on_segment(point c);

};

double distance(point a, point b);

#endif