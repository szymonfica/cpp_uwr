#include "queue.hpp"

int main() {

    queue Q1;
    queue Q2(4);
    queue Q3({"a", "b", "c"});
    //queue Q3 {"a", "b", "c"};
    cout<< "Front Q3: " << Q3.front() << '\n';
    queue Q4 = Q3;
    queue Q5 = std::move(Q3);
    cout<< "Q3 " << Q3.to_string() << '\n';
    cout<< "Q4 " << Q4.to_string() << '\n';
    cout<< "Q5 " << Q5.to_string() << '\n';
    try {
        Q2.insert("a"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("b"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.pop(); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("c"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("d"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("e"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        Q2.insert("f"); }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< Q2.to_string() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    try {
        cout<< "Front: " << Q2.pop() << '\n'; }
    catch(invalid_argument const& ex) {
        cerr << ex.what() << '\n'; }
    
    


    
    return 0;
}