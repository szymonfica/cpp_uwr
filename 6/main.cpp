#include "polynomial.hpp"

int main() {

    polynomial w1({1, 2, 3, 4});
    
    polynomial w2;
    cin>> w2;
    w2 = w2 * 4.0;
    try {
        cout<< "w1 " << w1 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    try {
        cout<< "w2 " << w2 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    try {
        cout<< "w1-w2 " << w1-w2 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    polynomial w3 = w1 + w2;
    try {
        cout<< "w3 " << w3 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    polynomial w4 = std::move(w3);
    try {
        cout<< "w3 " << w3 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    try {
        cout<< "w4 " << w4 << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }
    try {
        cout<< "w4(3) =  " << w4(3) << '\n'; }
    catch(invalid_argument* const& ex) {
        cerr << ex->what() << '\n'; }


    return 0;
}