#include "pixel.hpp"

pixel::pixel()
    : x(0), y(0) {}
pixel::pixel(int x, int y) {
    if(x < 0 || y < 0 || x > X || y > Y) {
        throw new invalid_argument("The coordinates are incorrect!");
    }
    this->x = x;
    this->y = y;
}
int pixel::get_x() {
    return this->x;
}
int pixel::get_y() {
    return this->y;
}
int pixel::dist_top() {
    return Y - this->y;
}
int pixel::dist_bottom() {
    return this->y;
}
int pixel::dist_left() {
    return this->x;
}
int pixel::dist_right() {
    return X - this->x;
}
int pixel::dist(pixel &p, pixel &q) {
    return sqrt((p.get_x() - q.get_x()) * (p.get_x() - q.get_x()) + (p.get_y() - q.get_y()) * (p.get_y() - q.get_y()));
}

int pixel::dist(pixel *p, pixel *q) {
    return sqrt((p->get_x() - q->get_x()) * (p->get_x() - q->get_x()) + (p->get_y() - q->get_y()) * (p->get_y() - q->get_y()));
}
