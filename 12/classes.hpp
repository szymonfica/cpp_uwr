#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>
#include <iomanip>

using namespace std;

namespace calculator {

class fun {
private:
    string name;
    vector<double> args;
    static inline unordered_map<string, int> D = {{"+", 2}, {"-", 2}, {"*", 2}, {"/", 2}, {"mod", 2}, {"log", 2}, {"pow", 2}, {"neg", 1}, {"ln", 1}, {"exp", 1}};

public:
    fun(string s, vector<double> v);
    double value(); 
    static bool is_fun(string s);
    static int degree(string s);
    
};
class symbol {
protected:
    double value;
public:
    double get_value();

};

class number : public symbol {
public:
    number(double x);
    number(string s);
};

class constant : public symbol {
private:
    string name;
    static inline unordered_map<string, double> C = {{"e", 2.718281828459}, {"pi", 3.141592653589}, {"fi", 1.618033988750}};

public:
    constant(string s, double x);
    constant(string s);
    static bool is_con(string s);
    static double get_value(string s);
};

class variable : public symbol {
private:
    string name;
    static inline unordered_map<string, double> V = {};
public:
    variable(string s, double x);
    variable(string s);
    void set_value(double x);
    static bool is_var(string s);
    static void clear();
    
};

}

#endif