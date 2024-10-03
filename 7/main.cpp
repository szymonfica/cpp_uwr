#include "color.hpp"
#include "color_named.hpp"
#include "color_tn.hpp"
#include "pixel.hpp"
#include "pixel_colored.hpp"
#include "color_tn.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "Testing the color class:" << '\n';

    color k1 = color();
    color k2 = color();
    color k3 = color();

    try {
        color k1(5, 10, 15); }
    catch (invalid_argument* const &ex) {
        cerr << ex->what() << '\n'; }

    try {
        color k2(256, 0, -5); }
    catch (invalid_argument* const &ex) {
        cerr << ex->what() << '\n'; }

    try {
        color k3(0, 8, 50); }
    catch (invalid_argument* const &ex) {
        cerr << ex->what() << '\n'; }

    cout << "red k1:" << k1.get_red() << '\n';
    cout << "green k1:" << k1.get_green() << '\n';
    cout << "blue k1:" << k1.get_blue() << '\n';

    k1.set_red(10);
    k1.set_green(9);
    k1.set_blue(8);
    cout << "red k1:" << k1.get_red() << '\n';
    cout << "green k1:" << k1.get_green() << '\n';
    cout << "blue k1:" << k1.get_blue() << '\n';

    k1.ciemniej();
    cout << "red k1:" << k1.get_red() << '\n';
    cout << "green k1:" << k1.get_green() << '\n';
    cout << "blue k1:" << k1.get_blue() << '\n';
    k1.jasniej();
    cout << "red k1:" << k1.get_red() << '\n';
    cout << "green k1:" << k1.get_green() << '\n';
    cout << "blue k1:" << k1.get_blue() << '\n';
    cout << "red after mix: " << color::mix(k1, k3).get_red() << '\n';
    cout << "green after mix: " << color::mix(k1, k3).get_green() << '\n';
    cout << "blue after mix: " << color::mix(k1, k3).get_blue() << '\n';
    cout << "Testing the color_named class" << '\n';
    color_named k7(5, 10, 15, "colora");
    cout << "Testing the color_transparent class" << '\n';
    color_transparent k10(8, 7, 3, 15);
    cout << "Testing the color_tn class" << '\n';
    color_tn k13(5, 7, 13, "colorb", 10);
    cout << "Testing the pixel class" << '\n';
    pixel p1(10, 15);
    cout << "x p1:" << p1.get_x() << '\n';
    cout << "y p1:" << p1.get_y() << '\n';
    cout << "up: " << p1.dist_top() << '\n';
    cout << "down: " << p1.dist_bottom() << '\n';
    cout << "left: " << p1.dist_left() << '\n';
    cout << "right: " << p1.dist_right() << '\n';
    cout << "Testing the pixel_colored class" << '\n';
    pixel_colored p2(10, 20, k10);
    p2.move_by_vector(10, 15);
    pixel p3(30, 49);
    cout << "Testing global functions:" << '\n';
    cout << "Distance 1:" << pixel::dist(p1, p3) << '\n';
    cout << "Distance 2:" << pixel::dist(&p1, &p3) << '\n';
}