#include "color_transparent.hpp"


color_transparent::color_transparent()
    : color_transparent(0, 0, 0, 255) {

}
color_transparent::color_transparent(unsigned short r, unsigned short g, unsigned short b)
    : color_transparent(r, g, b, 255) {

}
color_transparent::color_transparent(unsigned short r, unsigned short g, unsigned short b, unsigned short a)
    : color::color(r, g, b) {
    if(a < 0 || a > 255) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
    this->alfa = a;
}
void color_transparent::set_alfa(unsigned short v) {
    if(v < 0 || v > 255) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
    this->alfa = v;
}
unsigned short color_transparent::get_alfa() {
    return this->alfa;
}

