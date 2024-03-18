#include "triangle.hpp"

triangle::triangle(point a, point b, point c) {
    if(a.getX() == b.getX() && a.getY() == b.getY()) {
        throw invalid_argument("error");
    }
    else if(a.getX() == c.getX() && a.getY() == c.getY()) {
        throw invalid_argument("error");
    }
    else if(b.getX() == c.getX() && b.getY() == c.getY()) {
        throw invalid_argument("error");
    }
    else {
        this->a = a;
        this->b = b;
        this->c = c;
    }
}
point triangle::get_A() { return this->a; }
point triangle::get_B() { return this->b; }
point triangle::get_C() { return this->c; }
void triangle::set_A(point p) {this->a = p; }
void triangle::set_B(point p) {this->b = p; }
void triangle::set_C(point p) {this->c = p; }
void triangle::translation(vec v) {
    this->get_A().translation(v);
    this->get_B().translation(v);
    this->get_C().translation(v);
}
void triangle::rotate(point p, double angle) {
    this->get_A().rotate(p, angle);
    this->get_B().rotate(p, angle);
    this->get_C().rotate(p, angle);
}
void triangle::cen_sym(point p) {
    this->get_A().cen_sym(p);
    this->get_B().cen_sym(p);
    this->get_C().cen_sym(p);
}
void triangle::sym_X() {
    this->get_A().sym_X();
    this->get_B().sym_X();
    this->get_C().sym_X();
}
void triangle::sym_Y() {
    this->get_A().sym_Y();
    this->get_B().sym_Y();
    this->get_C().sym_Y();
}
void triangle::sym_line(linear l) {
    this->get_A().sym_line(l);
    this->get_B().sym_line(l);
    this->get_C().sym_line(l);
}
double triangle::perimeter() {
    return ::distance(a, b) + ::distance(b, c) + ::distance(c, a);
}
double triangle::area() {
    double x = ::distance(a, b), y = ::distance(b, c), z = ::distance(c, a);
    double p = (x+y+z) / 2.0;
    return sqrt(p * (p-x) * (p-y) * (p-z));
}
bool triangle::point_inside_triangle(point p) {
    vec AB, AC, AP;
    AB.setX(this->b.getX() - this->a.getX());
    AB.setY(this->b.getY() - this->a.getY());
    AC.setX(this->c.getX() - this->a.getX());
    AC.setY(this->c.getY() - this->a.getY());
    AP.setX(p.getX() - this->a.getX());
    AP.setY(p.getY() - this->a.getY());
    double first = AB.getX() * AP.getY() - AB.getY() * AP.getX();
    double second = AC.getX() * AP.getY() - AC.getY() * AP.getX();
    return first * second > 0;
}

bool parallel(segment a, segment b) {
    double aa = a.get_A().getX() - a.get_B().getX();
    double bb = a.get_A().getY() - a.get_B().getY();
    double cc = b.get_A().getX() - b.get_B().getX();
    double dd = b.get_A().getY() - b.get_B().getY();
    return aa * dd == cc * bb;
}
bool perpendicular(segment a, segment b) {
    double f = (a.get_A().getY() - a.get_B().getY()) / (a.get_A().getX() - a.get_B().getX());
    double g = (b.get_A().getY() - b.get_B().getY()) / (b.get_A().getX() - b.get_B().getX());
    return f * g == -1.0;
}
bool on_segment(point p, point q, point r) { 
    if (q.getX() <= max(p.getX(), r.getX()) && q.getX() >= min(p.getX(), r.getX()) && 
        q.getY() <= max(p.getY(), r.getY()) && q.getY() >= min(p.getY(), r.getY())) 
       return true; 
    return false; 
}
int orientation(point p, point q, point r) {
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - 
              (q.getX() - p.getX()) * (r.getY() - q.getY()); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool intersect(segment a, segment b) {
    point p1 = a.get_A(), p2 = a.get_B();
    point q1 = b.get_A(), q2 = b.get_B();
    int o1 = ::orientation(p1, q1, p2); 
    int o2 = ::orientation(p1, q1, q2); 
    int o3 = ::orientation(p2, q2, p1); 
    int o4 = ::orientation(p2, q2, q1); 
    if (o1 != o2 && o3 != o4) { return true; }
    if (o1 == 0 && ::on_segment(p1, p2, q1)) return true; 
    if (o2 == 0 && ::on_segment(p1, q2, q1)) return true; 
    if (o3 == 0 && ::on_segment(p2, p1, q2)) return true; 
    if (o4 == 0 && ::on_segment(p2, q1, q2)) return true; 
    return false;
}
bool disjoint(triangle a, triangle b) {
    segment A = segment(a.get_A(), a.get_B());
    segment B = segment(a.get_A(), a.get_C());
    segment C = segment(a.get_B(), a.get_C());
    segment D = segment(b.get_A(), b.get_B());
    segment E = segment(b.get_B(), b.get_C());
    segment F = segment(b.get_A(), b.get_C());
    return intersect(A, D) || intersect(A, E) || intersect(A, F) || intersect(B, D) || intersect(B, E) || intersect(B, F) || intersect(C, D) || intersect(C, E) || intersect(C, F);
}
bool contains(triangle a, triangle b) {
    double x = (b.get_A().getX() + b.get_B().getX() + b.get_C().getX())/3;
    double y = (b.get_A().getY() + b.get_B().getY() + b.get_C().getY())/3;
    point p(x, y);
    return a.point_inside_triangle(p) && disjoint(a, b);
}