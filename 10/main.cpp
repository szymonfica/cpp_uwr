#include "bst.hpp"

using namespace std;

int main() {

    bst<int> a;
    a.add(10);
    a.add(5);
    a.add(15);
    a.add(3);
    a.add(7);
    a.add(12);
    a.add(18);

    std::cout << "BST after adding values: " << a << std::endl;

    a.remove(10);

    std::cout << "BST after removing 10: " << a << std::endl;

    bst<int>* tree = new bst<int>();
    int choice, value;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Print tree" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                tree->add(value);
                break;

            case 2:
                cout << "Enter value to remove: ";
                cin >> value;
                tree->remove(value);
                break;

            case 3:
                cout << "Tree: " << *tree << endl;
                break;

            case 4:
                delete tree;
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }


    return 0;
}
