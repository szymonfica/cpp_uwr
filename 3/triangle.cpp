#include "triangle.hpp"

double dummy_area(int x1, int y1, int x2, int y2, int x3, int y3) {
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
triangle::triangle(point a, point b, point c) {
    try {
        if(::dummy_area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY()) == 0) {
            throw invalid_argument("Error: Triangle must consist of three non-collinear points.");
        }
        if(a.getX() == b.getX() && a.getY() == b.getY()) {
            throw invalid_argument("Error: Triangle must consist of three different points.");
        }
        else if(a.getX() == c.getX() && a.getY() == c.getY()) {
            throw invalid_argument("Error: Triangle must consist of three different points.");
        }
        else if(b.getX() == c.getX() && b.getY() == c.getY()) {
            throw invalid_argument("Error: Triangle must consist of three different points.");
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
triangle::triangle(const triangle& t) {
    this->a = t.a;
    this->b = t.b;
    this->c = t.c;
}
point triangle::get_A() { return this->a; }
point triangle::get_B() { return this->b; }
point triangle::get_C() { return this->c; }
void triangle::set_A(point p) {this->a = p; }
void triangle::set_B(point p) {this->b = p; }
void triangle::set_C(point p) {this->c = p; }
void triangle::translation(vec v) {
    this->a.translation(v);
    this->b.translation(v);
    this->c.translation(v);
}
void triangle::rotate(point p, double angle) {
    this->a.rotate(p, angle);
    this->b.rotate(p, angle);
    this->c.rotate(p, angle);
}
void triangle::cen_sym(point p) {
    this->a.cen_sym(p);
    this->b.cen_sym(p);
    this->c.cen_sym(p);
}
void triangle::sym_X() {
    this->a.sym_X();
    this->b.sym_X();
    this->c.sym_X();
}
void triangle::sym_Y() {
    this->a.sym_Y();
    this->b.sym_Y();
    this->c.sym_Y();
}
void triangle::sym_line(linear l) {
    this->a.sym_line(l);
    this->b.sym_line(l);
    this->c.sym_line(l);
}
double triangle::perimeter() {
    return ::distance(a, b) + ::distance(b, c) + ::distance(c, a);
}
double triangle::area() {
    double x = ::distance(a, b), y = ::distance(b, c), z = ::distance(c, a);
    double p = (x+y+z) / 2.0;
    return sqrt(p * (p-x) * (p-y) * (p-z));
}
bool dummy_inside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {   
    float A = dummy_area(x1, y1, x2, y2, x3, y3);
    float A1 = dummy_area (x, y, x2, y2, x3, y3);
    float A2 = dummy_area (x1, y1, x, y, x3, y3);
    float A3 = dummy_area (x1, y1, x2, y2, x, y);
    return (A == A1 + A2 + A3);
}
bool triangle::point_inside_triangle(point p) {
    return dummy_inside(this->get_A().getX(), this->get_A().getX(),
                        this->get_B().getX(), this->get_B().getX(),
                        this->get_C().getX(), this->get_C().getX(), 
                        p.getX(), p.getY());
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