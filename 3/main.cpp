#include "triangle.hpp"

using namespace std;

int main() {

    point* A = new point(1, 5);
    point* B = new point(6, -2);
    point* C = new point(*A);
    segment* AB = new segment(A, B);
    segment* AB2 = new segment(*AB);
    //AB->get_A().setX(10);
    A->setX(11);
    C->setX(12);
    cout<< "A: " <<  A->getX() << ' ' << A->getY() << '\n';
    cout<< "B: " << B->getX() << ' ' << B->getY() << '\n';
    cout<< "C: " << C->getX() << ' ' << C->getY() << '\n';
    cout<< "eureca!!\n";
    AB->get_A()->getX();
    cout<< AB->get_A().getX() << ' ' << AB->get_A().getY() << '\n';
    cout<< AB->get_B().getX() << ' ' << AB->get_B().getY() << '\n';
    

    delete A;
    delete B;
    delete C;
    delete AB;
    
    return 0;
}