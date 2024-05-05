#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

class polynomial{
private:
    int n;
    double* a;

public:
    polynomial();
    polynomial(int n);
    polynomial(int n, double c);
    polynomial(int n, const double a[]);
    polynomial(initializer_list<double> lst);
    polynomial(const polynomial &p);
    polynomial(polynomial &&p);
    polynomial& operator=(const polynomial &other);
    polynomial& operator=(polynomial &&other);
    ~polynomial();

    friend istream& operator>>(istream &we, polynomial &w);
    friend ostream& operator<<(ostream &wy, const polynomial &w);

    friend polynomial operator+(const polynomial &u, const polynomial &v);
    friend polynomial operator-(const polynomial &u, const polynomial &v);
    friend polynomial operator*(const polynomial &u, const polynomial &v);
    friend polynomial operator*(const polynomial &u, double c);
    friend polynomial operator*(double c, const polynomial &u);
    polynomial& operator+=(const polynomial &other);
    polynomial& operator-=(const polynomial &other);
    polynomial& operator*=(const polynomial &other);
    polynomial& operator*=(double c);
    double operator() (double x) const;
    double operator[] (int i) const;
    double& operator[] (int i);

    const int get_n();

};



#endif