#include "classes.hpp"

namespace calculator {

number::number(double x){
    this->value = x;
}
number::number(string s) {
    this->value = stod(s);
}
constant::constant(string s, double x) {
    this->name = s;
    this->value = x;
    C.insert({s, x});
}
constant::constant(string s) {
    this->name = s;
    this->value = C[s];
}
double constant::get_value(string s) {
    return C[s];
}
variable::variable(string s, double x) {
    if(fun::is_fun(s)) {
        throw invalid_argument("Variable can not be named the same as a function!");
    }
    if(constant::is_con(s)) {
        throw invalid_argument("Variable can not be named the same as a constant!");
    }
    if(s.size() > 7) {
        throw invalid_argument("Variable can not be longer than 7!");
    }
    if(s == "print" || s == "set" || s == "to" || s == "clear" || s == "exit") {
        throw invalid_argument("Variable can not be named print/set/to/clear/exit!");
    }
    this->name = s;
    this->value = x;
    V.insert({s, x});
}
variable::variable(string s) {
    this->name = s;
    this->value = variable::V[s];
    V.insert({s, this->value});
}
void variable::set_value(double x) {
    this->value = x;
    V[this->name] = x;
}
void variable::clear() {
    variable::V.clear();
}
double symbol::get_value() {
    return this->value;
}
fun::fun(string s, vector<double> v) : name(s), args(v) {}
double fun::value() {
        if(name == "+")
            return args[0] + args[1];
        else if(name == "-")
            return args[0] - args[1];
        else if(name == "*")
            return args[0] * args[1];
        else if(name == "/")
            return args[0] / args[1];
        else if(name == "mod")
            return fmod(args[0], args[1]);
        else if(name == "log")
            return log2(args[0]) / log2(args[1]);
        else if(name == "pow")
            return pow(args[0], args[1]);
        else if(name == "neg")
            return -args[0];
        else if(name == "ln")
            return log(args[0]);
        else if(name == "exp")
            return exp(args[0]);
        else
            return 0;
}
int fun::degree(string s) {
    return D[s];
}
bool fun::is_fun(string s) {
    return D.count(s);
}
bool constant::is_con(string s) {
    return C.count(s);
}
bool variable::is_var(string s) {
    return V.count(s);
}

}