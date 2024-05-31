#include "Vector.hpp"


int main(){
    
    Vector<int> vector;
    vector.pushBack(3);
    vector.pushBack(12);
    vector.pushBack(5);
    vector.pushBack(5);
    vector.pushBack(1);
    vector.pushBack(9);
    
    vector.remove(2);
    vector.remove(0);
    vector.insert(1, 3);
    vector.print();
}
