#include "number.hpp"

int main() {

    number x = number();
    x.set(5);
    x.set(4);
    x.set(12);
    x.set(15);
    cout<< "current value of x: " << x.get() << '\n';
    x.previous();
    cout<< "current value of x: " << x.get() << '\n';
    x.previous();
    cout<< "current value of x: " << x.get() << '\n';
    number a = number(5);
    a.set(3);
    a.set(2);
    number b = a;
    cout<< "current value of b: "  << b.get() << '\n';
    number c;
    c = std::move(b);
    cout<< "current value of c: "  << c.get() << '\n';
    c.set(3);
    c.set(4);
    c.previous();
    cout<< "current value of c: "  << c.get() << '\n';
    c.previous();
    cout<< "current value of c: " << c.get() << '\n';
    try {
        cout<< "1st previous value c: " << c.get_previous(1) << '\n';
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }
    try {
        cout<< "2nd previous value c: " << c.get_previous(2) << '\n';
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }
    try {
        cout<< "3rd previous value c: " << c.get_previous(3) << '\n';
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }
    try {
        cout<< "4th previous value c: " << c.get_previous(4) << '\n';
    }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n';
    }


    return 0;
}