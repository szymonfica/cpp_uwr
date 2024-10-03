#ifndef COLOR_NAMED_HPP
#define COLOR_NAMED_HPP

#include "color.hpp"

class color_named : public virtual color{
protected:
    string name;

public:
    color_named();
    color_named(unsigned short r, unsigned short g, unsigned short b);
    color_named(unsigned short r, unsigned short g, unsigned short b, string name);

    void set_name(string name);

    string get_name();


};


#endif