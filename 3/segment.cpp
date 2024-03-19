#include "segment.hpp"

segment::segment(point a, point b) {
    try {
        if(a.getX() == b.getX() && a.getY() == b.getY()) {
            throw invalid_argument("Error: Segment must consist of two different points.");
        }
        else {
            this->a = a;
            this->b = b;
        }
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }
}
segment::segment(const segment& s) {
    this->a = s.a;
    this->b = s.b;
}
point segment::get_A() { return this->a; }
point segment::get_B() { return this->b; }
void segment::set_A(point p) {this->a = p; }
void segment::set_B(point p) {this->b = p; }
void segment::translation(vec v) {
    this->a.translation(v);
    this->b.translation(v);
}
void segment::rotate(point p, double angle) {
    this->a.rotate(p, angle);
    this->b.rotate(p, angle);
}
void segment::cen_sym(point p) {
    this->a.cen_sym(p);
    this->b.cen_sym(p);
}
void segment::sym_X() {
    this->a.sym_X();
    this->b.sym_X();
}
void segment::sym_Y() {
    this->a.sym_Y();
    this->b.sym_Y();
}
void segment::sym_line(linear l) {
    this->a.sym_line(l);
    this->b.sym_line(l);
}
double distance(point a, point b) {
    double dist_x = a.getX()-b.getX();
    double dist_y = a.getY()-b.getY();
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}
double segment::length() { return ::distance(a, b); }
bool segment::point_on_segment(point c) {
    return ::distance(a, b) == ::distance(a, c) + ::distance(c, b);
}