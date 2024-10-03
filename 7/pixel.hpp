#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

class pixel{
protected:
    int x, y;
    static const int X = 1920, Y = 1080; 

public:
    pixel();
    pixel(int x, int y);
    
    int get_x();
    int get_y();
    int dist_top();
    int dist_bottom();
    int dist_left();
    int dist_right();

    static int dist(pixel &p, pixel &q);
    static int dist(pixel *p, pixel *q);

};


#endif