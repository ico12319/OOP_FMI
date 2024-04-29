
#include <iostream>
#include "MultiSet.h"

int main(int argc, const char * argv[]) {
    
    MultiSet set(8,3);
    set.add(2);
    set.add(2);
    set.add(2);
    set.add(2);
    set.add(14);
    set.add(0);
    set.add(4);
    set.add(8);
    set.add(3);
    set.add(1);
    set.add(2);
    set.add(2);
    set.add(2);
    set.add(2);
    set.add(2);
    
    
    set.print();
}
