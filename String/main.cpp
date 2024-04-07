#include <iostream>
#include "Istring.h"

int main(int argc, const char * argv[]) {
    
    
    Istring str1("Hello");
    Istring str2("Kaba");
    Istring str3("madam");
    
    
    str1(3);
    
    
    size_t len = str1.getLength();
    
    std::cout<<str1<<std::endl;
    
    
    
}
