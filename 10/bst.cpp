#include "bst.hpp"


template <typename T>
bst<T>::node::node() : node(T()) {}
template <typename T>
bst<T>::node::node(const T& val) : value(val), left(nullptr), right(nullptr) {}
template <typename T>
typename bst<T>::node* bst<T>::copy_node(const node* v) {
    if(v == nullptr)
        return nullptr;
    node* w = new node(v->value);
    w->left = copy_node(v->left);
    w->right = copy_node(v->right);
    return w;
}
template <typename T>
void bst<T>::delete_node(node* root) {
    if(root != nullptr) {
        delete_node(root->left);
        delete_node(root->right);
        delete root;
    }
}

template <typename T>
bst<T>::bst() {
    root = nullptr;
    //root = new node(T());
}
template <typename T>
bst<T>::bst(initializer_list<T> lst) {
    root = new node(T());
    for(T i : lst) {
        add(i);
    }
}
template <typename T>
bst<T>::bst(bst &&other) {
    swap(this->root, other.root);
    other.delete_node(other.root);
}
template <typename T>
bst<T>::bst(const bst<T>& other) : root(nullptr) {
    if(other.root != nullptr) {
        root = copy_node(other.root);
    }
}
template <typename T>
bst<T>& bst<T>::operator= (const bst &other) {
    if(this != &other) {
        delete_node(this->root);
        root = copy_node(other.root);
    }
    return *this;
}
template <typename T>
bst<T>& bst<T>::operator= (bst &&other) {
    if(this != &other) {
        this->root = other.root;
        other.root = nullptr;
    }
    return *this;
}
template <typename T>
bst<T>::~bst() {
    delete_node(root);
}
template <typename T>
void bst<T>::add(T value) {
    if(root == nullptr) {
        root = new node(value);
        return;
    }
    node* v = root;
    node* parent = nullptr;
    while(v != nullptr) {
        parent = v;
        if(value < v->value) {
            v = v->left;
        }
        else {
            v = v->right;
        }
    }
    if(value < parent->value)
        parent->left = new node(value);
    else
        parent->right = new node(value);
}

template <typename T>
bool bst<T>::check(T value) {
    node* v = root;
    while(v != nullptr) {
        if(value == v->value)
            return true;
        else if(value < v->value)
            v = v->left;
        else
            v = v->right;
    }
    return false;
}
template <typename T>
void bst<T>::remove(T value) {
    root = remove_node(root, value);
}

template <typename T>
typename bst<T>::node* bst<T>::remove_node(node* start, T value) {
    if(start == nullptr)
        return start;
    node* v = start;
    if(value < v->value) {
        v->left = remove_node(v->left, value);
    }
    else if(value > v->value) {
        v->right = remove_node(v->right, value);
    }
    else {
        if(v->left == nullptr) {
            node* temp = v->right;
            delete root;
            return temp;
        }
        else if(v->right == nullptr) {
            node* temp = v->left;
            delete v;
            return temp;
        }
        node* temp = find_min(v->right);
        v->value = temp->value;
        v->right = remove_node(v->right, v->value);
    }
    return v;
}

template <typename T>
typename bst<T>::node* bst<T>::find_min(node* start) {
    node* v = start;
    while (v->left != nullptr) {
        v = v->left;
    }
    return v;
}


template <typename T>
void bst<T>::inOrderTraversal(ostream &out, node* root) const {
    if(root != nullptr) {
        inOrderTraversal(out, root->left);
        out << root->value << " ";
        inOrderTraversal(out, root->right);
    }
}

template <typename T>
ostream& operator<<(ostream &out, const bst<T> &tree) {
    tree.inOrderTraversal(out, tree.root);
    return out;
}
template class bst<int>;
template class bst<double>;
template class bst<string>;
template ostream& operator<< (ostream &out, const bst<int> &tree);
template ostream& operator<< (ostream &out, const bst<double> &tree);
template ostream& operator<< (ostream &out, const bst<string> &tree);