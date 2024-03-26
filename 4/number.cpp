#include "number.hpp"

number::number() :  number(0.0) {}
number::number(double x) {
    history = new double[history_len];
    idx = 0,
    currently_remembered = 1;
    history[idx] = x;
}
number::number(number &other) : number(other.get()) {}
number::number(number &&other) {
    this->history = other.history;
    this->idx = other.idx;
    this->currently_remembered = other.currently_remembered;
    other.history = nullptr;
}
number& number::operator=(number &other) {
    this->set(other.get());
    return *this;
}
number& number::operator=(number &&other) {
    if(this != &other) {
        this->history = other.history;
        this->idx = other.idx;
        this->currently_remembered = other.currently_remembered;
        other.history = nullptr;
    }
    return *this;
}
number::~number() {
    delete[] history;
}
const double number::get() {
    return this->history[this->idx];
}
const double number::get_previous(int n) {
    if(n > this->currently_remembered) {
        throw invalid_argument("Index out of range.");
    }
    return this->history[((this->idx)-n+currently_remembered)%currently_remembered];
}
void number::set(double y) {
    idx = (idx+1)%number::history_len;
    currently_remembered = max(currently_remembered+1, number::history_len);
    history[idx] = y;
}
void number::previous() {
    if(currently_remembered == 1) { return; }
    currently_remembered -= 1;
    idx = (idx-1+number::history_len)%number::history_len;
}