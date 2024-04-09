#include "queue.hpp"

queue::queue(int n) 
    : capacity(n), cnt(0), idx(0) {
    if(n <= 0) {
        throw invalid_argument("Error: n < 0 !!");
    }
    arr = new string[this->capacity];
}
queue::queue() : queue(1) {}
queue::queue(initializer_list<string> lst) : queue(lst.size()) {
    for(auto i : lst) {
        this->arr[this->cnt] = i;
        this->cnt++;
    }
}
queue::queue(queue &other) : queue(other.capacity) {
    this->cnt = other.cnt;
    for(int i=0; i<this->cnt; i++) {
        this->arr[i] = other.arr[(i+idx)%other.capacity];
    }
}
queue::queue(queue &&other)
    : arr(other.arr), idx(other.idx), cnt(other.cnt), capacity(other.capacity) {
    other.arr = nullptr;
}
queue& queue::operator=(queue &other){
    if(this != &other) {
        this->idx = other.idx;
        this->cnt = other.cnt;
        this->capacity = other.capacity;
        this->arr = new string[this->capacity];
        //this->arr = other.arr;
        for(int i=0; i<this->capacity; i++) {
            this->arr[i] = other.arr[(i+idx)%other.capacity];
        }
    }
    return *this;
}
queue& queue::operator=(queue &&other) {
    if(this != &other) {
        this->arr = other.arr;
        this->idx = other.idx;
        this->cnt = other.cnt;
        this->capacity = other.capacity;
        other.arr = nullptr;
        other.capacity = 0;
        other.cnt = 0;
        other.idx = 0;
    }
    return *this;
}
queue::~queue() {
    delete[] arr;
}
void queue::insert(string s) {
    if(cnt >= capacity) {
        throw invalid_argument("Queue is full.");
    }
    this->arr[(this->idx+this->cnt+this->capacity)%this->capacity] = s;
    this->cnt++;
}
string queue::pop() {
    if(cnt == 0) {
        throw invalid_argument("Queue is empty.");
    }
    this->idx = (this->idx+1)%this->capacity;
    this->cnt--;
    return this->arr[(this->idx - 1 + this->capacity)%this->capacity];
}
string queue::front() {
    if(cnt == 0) {
        throw invalid_argument("Queue is empty.");
    }
    return this->arr[this->idx];
}
int queue::length() {
    return this->cnt;
}
string queue::to_string() {
    if(this->arr == nullptr) {
        return "Queue is empty!";
    }
    string result = "Queue: ";
    for(int i=0; i<this->cnt; i++) {
        result += this->arr[(this->idx+i)%this->capacity] + ", ";
    }
    return result;
}