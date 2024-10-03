#include "color_named.hpp"

color_named::color_named()
    : color() {
    this->name = "";
}
color_named::color_named(unsigned short r, unsigned short g, unsigned short b)
    : color(r, g, b) {
    this->name = "";
}
color_named::color_named(unsigned short r, unsigned short g, unsigned short b, string name)
    : color(r, g, b) {
    for(char c : name) {
        if(c < 'a' || c > 'z') {
            throw new invalid_argument("The name must consist of lowercase letters!");
        }
    }
    this->name = name;
}
void color_named::set_name(string name) {
    for(char c : name) {
        if(c < 'a' || c > 'z') {
            throw new invalid_argument("The name must consist of lowercase letters!");
        }
    }
    this->name = name;
}
string color_named::get_name() {
    return this->name;
}