#ifndef BST_HPP
#define BST_HPP

#include <iostream>

using namespace std;


template <typename T> class bst {
public:

    class node {
    private:
        node* left;
        node* right;
        T value;

    public:

        node();
        node(const T& value);

        friend class bst<T>;

    };

    node* root;

    bst();
    bst(initializer_list<T> lst);
    
    bst(const bst &other);
    bst(bst &&other);
    bst& operator=(const bst &other);
    ~bst();
    bst& operator=(bst &&other);

    void add(T value);
    void remove(T value);
    bool check(T value);
    node* find_min(node* start);
    node* remove_node(node* root, T value);
    node* copy_node(const node* root);
    void delete_node(node* root);

    void inOrderTraversal(ostream &out, node* root) const;

    template <typename U>
    friend ostream& operator<< (ostream& out, const bst<U>& tree);

};

#endif