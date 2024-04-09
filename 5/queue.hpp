#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

class queue {
private:
    int capacity, cnt, idx;
    string* arr;

public:

    queue();
    queue(int n);
    queue(initializer_list<string> lst);
    queue(queue &other);
    queue &operator=(queue &other);
    queue(queue &&other);
    queue &operator=(queue &&other);
    ~queue();
    void insert(string s);
    string pop();
    string front();
    int length();
    string to_string();
};






#endif