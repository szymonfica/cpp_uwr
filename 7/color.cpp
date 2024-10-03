#include "color.hpp"

color::color()
    : red(0), green(0), blue(0) {
}
color::color(unsigned short r, unsigned short g, unsigned short b)
    : red(r), green(g), blue(b) {
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
}
void color::set_red(unsigned short v) {
    if(v < 0 || v > 255 ) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
    this->red = v;
}
void color::set_green(unsigned short v) {
    if(v < 0 || v > 255 ) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
    this->green = v;
}
void color::set_blue(unsigned short v) {
    if(v < 0 || v > 255 ) {
        throw new invalid_argument("Colors must have values in the range: [0, 255]!");
    }
    this->blue = v;
}
unsigned short color::get_red() {
    return this->red;
}
unsigned short color::get_green() {
    return this->green;
}
unsigned short color::get_blue() {
    return this->blue;
}
void color::jasniej() {
    if(this->red < 255) this->red++;
    if(this->green < 255) this->green++;
    if(this->blue < 255) this->blue++;
}
void color::ciemniej() {
    if(this->red > 0) this->red--;
    if(this->green > 0) this->green--;
    if(this->blue > 0) this->blue--;
}
color color::mix(color a, color b) {
    return color((a.get_red() + b.get_red())/2,
                 (a.get_green() + b.get_green())/2,
                 (a.get_blue() + b.get_blue())/2);
}
