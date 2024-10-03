#include "color_tn.hpp"

color_tn::color_tn()
    : color_named::color_named(),
      color_transparent::color_transparent() {}

color_tn::color_tn(int r, int g, int b, string n, int a)
    : color_named::color_named(r, g, b, n),
      color_transparent::color_transparent(r, g, b, a) {}