#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <string>

using namespace std;

class rational_exception : public logic_error {
protected:

public:
    rational_exception();

};
class division_by_zero : public rational_exception { };
class number_out_of_range : public rational_exception { };




#endif