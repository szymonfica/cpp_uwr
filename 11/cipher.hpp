#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class input {
private:
    int key;
    char decrypt(char c);
    ifstream file;

public:
    input(const string &filename);
    ~input();

    void set_key(int k);
    string get_input();
    bool end_of_file();
};

class output {
private:
    ofstream file;
    int key;
    char encrypt_char(char c);

public:
    output(const string &filename);
    ~output();

    void set_key(int k);
    void pisz(const string &text);
};

#endif