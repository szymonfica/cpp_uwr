#ifndef COLOR_TRANSSPARENT_HPP
#define COLOR_TRANSSPARENT_HPP

#include "color.hpp"

class color_transparent : public virtual color{
protected:
    unsigned short alfa;

public:
    color_transparent();
    color_transparent(unsigned short r, unsigned short g, unsigned short b);
    color_transparent(unsigned short r, unsigned short g, unsigned short b, unsigned short a);

    void set_alfa(unsigned short v);

    unsigned short get_alfa();


};


#endif