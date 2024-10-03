#ifndef COLOR_TN_HPP
#define COLOR_TN_HPP

#include "color_named.hpp"
#include "color_transparent.hpp"

class color_tn : public color_named, public color_transparent {

protected:
    
public:
    color_tn();
    color_tn(int r, int g, int b, string n, int a);
};





#endif