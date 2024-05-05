#include "polynomial.hpp"


polynomial::polynomial() : polynomial(1, 1){

}
polynomial::polynomial(int n) : polynomial(n, 1){

}
polynomial::polynomial(int n, double c)
    : n(n) {
    if(n < 0){
        throw invalid_argument("Degree must be positive.");
    }
    this->a = new double[this->n+1];
    for(int i=0; i<=n; i++){
        a[i] = 0;
    }
    this->a[n] = c;
}
polynomial::polynomial(int n, const double a[]) 
    : n(n) {
    if(n < 0){
        throw invalid_argument("Degree must be positive.");
    }
    this->a = new double[this->n+1];
    for(int i=0; i<n; i++) {
        this->a[i] = a[i];
    }
}
polynomial::polynomial(initializer_list<double> lst)
    : n(lst.size()-1) {
    if(n < 0){
        throw invalid_argument("Degree must be positive.");
    }
    this->a = new double[this->n+1];
    int idx = 0;
    for(auto i : lst) {
        this->a[idx] = i;
        idx++;
    }
}
polynomial::polynomial(const polynomial &other)
    : n(other.n), a(new double [other.n+1]) {
    for(int i=0; i<this->n; i++) {
        this->a[i] = other.a[i];
    }
}
polynomial::polynomial(polynomial &&other)
    : n(other.n) {
    swap(this->a, other.a);
}
polynomial& polynomial::operator=(const polynomial &other) {
    if(this != &other) {
        this->n = other.n;
        this->a = new double[this->n+1];
        for(int i=0; i<=this->n; i++) {
            this->a[i] = other.a[i];
        }
    }
    return *this;
}
polynomial& polynomial::operator=(polynomial &&other) {
    if(this != &other) {
        this->n = other.n;
        this->a = other.a;
        other.a = nullptr;
        other.n = 0;
    }
    return *this;
}
polynomial::~polynomial() {
    delete[] a;
}
const int polynomial::get_n(){
    return this->n;
}

double polynomial::operator() (double x) const{
    double value = 0.0;
    double y = 1.0;
    for(int i=0; i<=this->n; i++){
        value += y * a[i];
        y *= x;
    }
    return value;
}
double polynomial::operator[] (int i) const {
    if(i < 0 || i > this->n){
        throw invalid_argument("Index must be between 0 and degree.");
    }
    return a[i];
}
double& polynomial::operator[] (int i){
    if(i < 0 || i > this->n){
        throw invalid_argument("Index must be between 0 and degree.");
    }
    return a[i];
}

polynomial& polynomial::operator+= (const polynomial &w){
    if(w.n <= this->n){
        for(int i=0; i<=w.n; i++){
            this->a[i] += w.a[i];
        }
    }
    else{
        double newa[w.n + 1];
        for(int i=0; i<=w.n; i++){
            if(i <= this->n){
                newa[i] = a[i] + w.a[i];
            }
            else{
                newa[i] = w.a[i];
            }
        }
        this->n = w.n;
        a = newa;
    } 
    return *this;

}
polynomial& polynomial::operator-= (const polynomial &w){
    if(w.n <= this->n){
        for(int i=0; i<=w.n; i++){
            this->a[i] -= w.a[i];
        }
    }
    else{
        double newa[w.n + 1];
        for(int i=0; i<=w.n; i++){
            if(i <= this->n){
                newa[i] = a[i] - w.a[i];
            }
            else{
                newa[i] = - w.a[i];
            }
        }
        this->n = w.n;
        a = newa; 
    } 
    return *this;
}
polynomial& polynomial::operator*= (const polynomial &w){
    int newDegree = this->n + w.n;
    double newa[newDegree + 1];

    for(int i=0; i<=newDegree; i++){
        newa[i] = 0;
    }
    for(int i=0; i<=this->n; i++){
        for(int j=0; j<=w.n; j++){
            newa[i + j] += this->a[i] * w.a[j];  
        }
    }
    this->n = newDegree;
    a = new double[this->n];
    for(int i=0; i<=this->n; i++){
        a[i] = newa[i];
    }
    return *this;
}
polynomial& polynomial::operator*= (double c){
    for(int i=0; i<=this->n; i++){
        a[i] *= c;
    }
    return *this;
}
polynomial operator+ (const polynomial &w, const polynomial &v){
    polynomial result = polynomial(max(w.n, v.n));
    if(w.n > v.n){
        for(int i=0; i<=w.n; i++){
            if(i <= v.n){
                result.a[i] = v.a[i] + w.a[i];
            }
            else{
                result.a[i] = w.a[i];
            }
        }
    }
    else{
        for(int i=0; i<=v.n; i++){
            if(i <= w.n){
                result.a[i] = w.a[i] + v.a[i];
            }
            else{
                result.a[i] = v.a[i];
            }
        }
    }
    return result;
}
polynomial operator- (const polynomial &w, const polynomial &v){
    polynomial result = polynomial(max(w.n, v.n));
    if(w.n > v.n){
        for(int i=0; i<=w.n; i++){
            if(i <= v.n){
                result.a[i] = w.a[i] - v.a[i];
            }
            else{
                result.a[i] = w.a[i];
            }
        }
    }
    else{
        for(int i=0; i<=v.n; i++){
            if(i <= w.n){
                result.a[i] = w.a[i] - v.a[i];
            }
            else{
                result.a[i] = -v.a[i];
            }
        }
    }
    return result;
}
polynomial operator* (const polynomial &w, const polynomial &v){
    polynomial result = polynomial(w.n + v.n);
    for(int i=0; i<=(w.n + v.n); i++){
        result.a[i] = 0;
    }
    for(int i=0; i<=w.n; i++){
        for(int j=0; j<=v.n; j++){
            result.a[i + j] += w.a[i] * v.a[j];
        }
    }
    return result;
}
polynomial operator* (const polynomial &w, double c){
    polynomial result = polynomial(w.n);

    for(int i=0; i<=w.n; i++){
        result.a[i] = w.a[i] * c;
    }
    return result;
}
polynomial operator* (double c, const polynomial &w){
    polynomial result = polynomial(w.n);

    for(int i=0; i<=w.n; i++){
        result.a[i] = w.a[i] * c;
    }
    return result;
}
istream& operator>> (istream &in, polynomial &w){
    cerr << "Enter the dimension of the polynomial:\n";
    in >> w.n;
    w.a = new double[w.n + 1];

    cerr << "Enter the next polynomial coefficients:\n";
    for(int i=0; i<=w.n; i++){
        in >> w.a[i];
    }
    return in;
}
ostream& operator<< (ostream &out, const polynomial &w){
    if(w.a == nullptr) {
        throw invalid_argument("Polynomial has been deleted.");
        return out;
    }
    for(int i=w.n; i>=0; i--){
        if(i == w.n){
            out << w.a[i] << "x^" << i << " ";
        }
        else if(i == 0){
            if(w.a[i] > 0){
                out << "+ " << w.a[i];
            }
            else{
                out << w.a[i];
            }
        }
        else{
            if(w.a[i] > 0){
                out << "+ " << w.a[i] << "x^" << i << " ";
            }
            else{
                out << w.a[i] << "x^" << i << " ";
            }
        }
    }
    return out;
}