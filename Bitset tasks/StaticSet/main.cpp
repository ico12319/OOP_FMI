#include <iostream>
#include "StaticSet.h"

int main(){
   
    StaticSet set;
    
    set.add(12);
    set.add(43);
    set.add(56);
    set.print();
    
    set.remove(43);
    set.print();
    
    std::cout<<set.contains(56)<<std::endl;

}
