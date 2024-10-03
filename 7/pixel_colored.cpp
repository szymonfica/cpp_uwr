#include "pixel_colored.hpp"

pixel_colored::pixel_colored()
    : pixel() {}

pixel_colored::pixel_colored(int x, int y, color k)
    : pixel(x, y) {
    this->k = k;
}
void pixel_colored::set_color(color k) {
    this->k = k;
}
void pixel_colored::move_by_vector(int a, int b) {
    if(this->get_x()+a < 0 || this->get_x()+a > this->X || this->get_y()+b < 0 || this->get_y()+b > this->Y ) {
        throw new invalid_argument("Coordinates went off screen!");
    }
    this->x = this->x + a;
    this->y = this->y + b;
}