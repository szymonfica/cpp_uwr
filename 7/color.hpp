#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

using namespace std;

class color{

protected:
    unsigned short red, green, blue;

public:
    color();
    color(unsigned short r, unsigned short g, unsigned short b);

    void set_red(unsigned short v);
    void set_blue(unsigned short v);
    void set_green(unsigned short v);

    unsigned short get_red();
    unsigned short get_green();
    unsigned short get_blue();

    void ciemniej();
    void jasniej();

    static color mix(color a, color b);

};





#endif