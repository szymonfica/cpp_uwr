#include "point.hpp"

point::point(double x, double y) {
    this->x = x;
    this->y = y;
}
point::point(const point &p) {
    this->x = p.x;
    this->y = p.y;
}
point::point() {
    this->x = 0;
    this->y = 0;
}
double point::getX() { return x; }
double point::getY() { return y; }
void point::setX(double x) { this->x = x; }
void point::setY(double y) { this->y = y; }
void point::translation(vec v) {
    this->setX(this->getX() + v.getX());
    this->setY(this->getY() + v.getY());
}
void point::rotate(point p, double angle) {
    double temp_x = this->getX() - p.getX();
    double temp_y = this->getY() - p.getY();
    angle = (angle*M_PI)/180;
    temp_x = temp_x*cos(angle) - temp_y*sin(angle);
    temp_y = temp_x*sin(angle) + temp_y*cos(angle);
    this->setX(temp_x);
    this->setY(temp_y);
}
void point::cen_sym(point p) {
    this->setX(2 * p.getX() - this->getX());
    this->setY(2 * p.getY() - this->getY());
}
void point::sym_X() {
    this->setY(-1.0 * this->getY());
}
void point::sym_Y() {
    this->setX(-1.0 * this->getX());
}
void point::sym_line(linear l) {
    double m = sqrt(l.getA()*l.getA() + l.getB()*l.getB());
    double aa = l.getA()/m, bb = l.getB()/m, cc = l.getC()/m;
    double d = aa * this->getX() + bb * this->getY() + cc;
    this->setX(this->getX() - 2 * aa * d);
    this->setY(this->getY() - 2 * bb * d);
}