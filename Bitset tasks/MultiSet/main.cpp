#include <iostream>
#include "MultiSet.h"



int main(int argc, const char * argv[]) {
    
    
    MultiSet set1(10,4);
    set1.add(1);
    set1.add(3);
    set1.add(5);
    set1.add(5);
    
    
    MultiSet set2;
   

    //std::ofstream ofs("ei sq mai stana.dat",std::ios::binary);
    //set.writeToBinary(ofs);
    std::ifstream ifs("ei sq mai stana.dat",std::ios::binary);
    set2.readFromBinary(ifs);
    
    set2.print();
    
   
}
