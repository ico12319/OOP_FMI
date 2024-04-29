#include <iostream>
#include "String.h"

int main(int argc, const char * argv[]) {
    
    
    String str = "Kisa";
    
    
    try{
        std::cout<<str[2]<<std::endl;
    }
    catch(const std::invalid_argument& exc){
        std::cout<<exc.what() << std::endl;
    }
    
}
