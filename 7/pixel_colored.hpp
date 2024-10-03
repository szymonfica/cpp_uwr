#ifndef PIXEL_COLORED_HPP
#define pixel_colored_HPP

#include "pixel.hpp"
#include "color.hpp"

class pixel_colored : public pixel{
protected:
    color k;

public:
    pixel_colored();
    pixel_colored(int x, int y, color k);

    void set_color(color k);

    void move_by_vector(int a, int b);


};


#endif