#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

class number {
private:
    double* history;
    int idx, currently_remembered;

public:
    inline static const int history_len = 3;

    number();
    number(double x);
    number(number &other);
    number &operator=(number &other);
    number(number &&other);
    number &operator=(number &&other);
    ~number();

    const double get();
    const double get_previous(int n);
    void set(double y);
    void previous();
};

#endif