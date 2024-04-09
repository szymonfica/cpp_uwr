#include "queue.hpp"

int main() {

    queue Q1;
    queue Q2(4);
    queue Q3({"a", "b", "c"});
    queue Q4 = Q3;
    queue Q5 = std::move(Q3);
    cout<< Q3.to_string() << '\n';
    cout<< Q4.to_string() << '\n';
    cout<< Q5.to_string() << '\n';
    try {
        Q2.insert("ala"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("ma"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.pop(); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
         }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("kota"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("oliwia"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< Q2.to_string() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front kolejki: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front kolejki: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front kolejki: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front kolejki: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    
    


    
    return 0;
}