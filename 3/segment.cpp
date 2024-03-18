#include "segment.hpp"

/*segment::segment(point a, point b) {
    if(a.getX() == b.getX() && a.getY() == b.getY()) {
        throw invalid_argument("error");
    }
    else {
        this->a = new point(a);
        this->b = new point(b);
    }
}*/
segment::segment(point* a, point* b) {
    if(a->getX() == b->getX() && a->getY() == b->getY()) {
        throw invalid_argument("error");
    }
    else {
        this->a = new point(*a);
        this->b = new point(*b);
    }
}
segment::segment(const segment& s) {
    this->a = new point(*s.a);
    this->b = new point(*s.a);
}
const point segment::get_A() { return *(this->a); }
const point segment::get_B() { return *(this->b); }
/*void segment::set_A(point p) {this->a = p; }
void segment::set_B(point p) {this->b = p; }
void segment::translation(vec v) {
    this->get_A().translation(v);
    this->get_B().translation(v);
}
void segment::rotate(point p, double angle) {
    this->get_A().rotate(p, angle);
    this->get_B().rotate(p, angle);
}
void segment::cen_sym(point p) {
    this->get_A().cen_sym(p);
    this->get_B().cen_sym(p);
}
void segment::sym_X() {
    this->get_A().sym_X();
    this->get_B().sym_X();
}
void segment::sym_Y() {
    this->get_A().sym_Y();
    this->get_B().sym_Y();
}
void segment::sym_line(linear l) {
    this->get_A().sym_line(l);
    this->get_B().sym_line(l);
}
double distance(point a, point b) {
    double dist_x = a.getX()-b.getX();
    double dist_y = a.getY()-b.getY();
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}
double segment::length() { return ::distance(a, b); }
bool segment::point_on_segment(point c) {
    return ::distance(a, b) == ::distance(a, c) + ::distance(c, b);
}*/