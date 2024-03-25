#include "number.hpp"


int main() {

    number x = number();
    x.set(5);
    x.set(4);
    x.set(4);
    x.set(12);
    x.set(15);
    cout << x.get() << '\n';
    x.previous();
    cout << x.get() << '\n';
    x.previous();
    cout << x.get() << '\n';

    number a = number(5);
    number b;
    a.set(3);
    a.set(2);
    b = a;
    cout << b.get() << '\n';
    number c;
    c = std::move(b);
    cout << c.get() << '\n';
    c.set(3);
    c.set(4);
    c.previous();
    cout << c.get() << '\n';
    c.previous();
    cout << c.get() << '\n';
    cout << c.get_previous(1) << '\n';
    cout << c.get_previous(2) << '\n';
    cout << c.get_previous(3) << '\n';
    cout << c.get_previous(4) << '\n';


    return 0;
}