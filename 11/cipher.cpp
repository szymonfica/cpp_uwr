#include "cipher.hpp"

char input::decrypt(char c) {
    if(!isalpha(c)) return c;
    char start = islower(c) ? 'a' : 'A';
    return (c - start - key + 26) % 26 + start;
}
input::input(const string &filename) : key(0) {
    file.open(filename);
    if(!file.is_open()) {
        throw ios_base::failure("Unable to open input file!");
    }
    file.exceptions(ifstream::badbit | ifstream::failbit);
}
input::~input() {
    if(file.is_open()) {
        file.close();
    }
}
void input::set_key(int k) {
    this->key = k % 26;
}
string input::get_input() {
    string line;
    getline(file, line);
    for (char &c : line) {
        c = decrypt(c);
    }
    return line;
}
bool input::end_of_file() {
    return this->file.eof();
}
char output::encrypt_char(char c) {
        if(!isalpha(c)) return c;
        char start = islower(c) ? 'a' : 'A';
        return (c - start + key + 26) % 26 + start;
}
output::output(const string &filename) : key(0) {
    file.open(filename);
    if(!file.is_open()) {
        throw ios_base::failure("Unable to open output file!");
    }
    file.exceptions(ofstream::badbit | ofstream::failbit);
}
output::~output() {
    if(file.is_open()) {
        file.close();
    }
}
void output::set_key(int k) {
    while(k < 0) {
        k += 26000;
    }
    this->key = k % 26;
}
void output::pisz(const string &text) {
    for (char c : text) {
        file.put(encrypt_char(c));
    }
    file.put('\n');
}