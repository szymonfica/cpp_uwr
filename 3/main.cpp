#include "triangle.hpp"

using namespace std;

int main() {

    point A = point(1, 5);
    point B = point(6, -2);
    point C = point(6, 6);
    segment AB = segment(A, B);
    segment BA = segment(AB);
    A.rotate(A, 50);
    vec u(4, 1);
    A.translation(u);
    B.cen_sym(A);
    AB = segment(A, B);
    BA = segment(AB);
    BA.rotate(B, 90);
    if(parallel(AB, BA)) cout << "Odcinki AB i BA sa rownlolegle\n";
    if(perpendicular(AB, BA)) cout << "Odcinki AB i BA sa prostopadle\n";
    segment AC = segment(A, C);
    segment BC = segment(B, C);
    triangle ABC = triangle(A, B, C);
    cout << "Trojkat ABC o punktach:\n";
    cout << "A:(" << A.getX() << ", " << A.getY() << ") ";
    cout << "B:(" << B.getX() << ", " << B.getY() << ") ";
    cout << "C:(" << C.getX() << ", " << C.getY() << ")\n";
    cout << "Ma pole " << ABC.area() << " i obwod " << ABC.perimeter();
    point O = point(10, 12);
    ABC.cen_sym(O);
    cout << "\nTrojkat ABC po wykonaniu symetri srodkowej wobec puntku O(" << O.getX() << ", " << O.getY() << "):\n";
    cout << "A:(" << (ABC.get_A()).getX() << ", " << (ABC.get_A()).getY() << ") ";
    cout << "B:(" << (ABC.get_B()).getX() << ", " << (ABC.get_B()).getY() << ") ";
    cout << "C:(" << (ABC.get_C()).getX() << ", " << (ABC.get_C()).getY() << ")\n";
    triangle DEF = triangle(ABC);
    vec v(-13, -20);
    DEF.translation(v);
    cout << "Trojkat DEF to trojkat ABC po translacji o wektor v = [-13, -20]\nJego punkty to:\n";
    cout << "D:(" << (DEF.get_A()).getX() << ", " << (DEF.get_A()).getY() << ") ";
    cout << "E:(" << (DEF.get_B()).getX() << ", " << (DEF.get_B()).getY() << ") ";
    cout << "F:(" << (DEF.get_C()).getX() << ", " << (DEF.get_C()).getY() << ")\n";
    DEF.sym_X();
    DEF.sym_Y();
    cout << "Trojkat DEF po nalozeniu na niego symetri osiowej wzgledem osi OX i OY:\n";
    cout << "D:(" << (DEF.get_A()).getX() << ", " << (DEF.get_A()).getY() << ") ";
    cout << "E:(" << (DEF.get_B()).getX() << ", " << (DEF.get_B()).getY() << ") ";
    cout << "F:(" << (DEF.get_C()).getX() << ", " << (DEF.get_C()).getY() << ")\n";
    point P = point(-3.5, 2);
    if(DEF.point_inside_triangle(P)) cout << "Punkt P(" << P.getX() << ", " << P.getY() << ") zawiera sie w trojkacie DEF\n"; 
    if(contains(ABC, DEF) == true) cout << "Trojakt ABC zawiera trojkat DEF\n";
    else if(disjoint(ABC, DEF) == true) cout << "Trojkaty ABC i DEF sa rozlaczne\n";
    else cout << "Trojkaty ABC i DEF sie przecinaja\n";

    
    return 0;
}