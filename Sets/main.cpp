#include "SetByString.h"


bool isEven(unsigned num){
    
    return (num % 2 == 0);
}

bool isOdd(unsigned num){
    return (!isEven(num));
}

int main(int argc, const char * argv[]) {
    
    
    SetByString set(12,"1 2 3 4 5 6 ");
    
    set.add(4);
    set.add(11);
    set.remove(11);
    set.print();
    
    std::cout<<set.contains(1)<<std::endl;
    
    
    
    
   
    
}
