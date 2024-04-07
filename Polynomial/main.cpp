#include <iostream>
#include "Polynomial.h"

int main(int argc, const char * argv[]) {
    
    int coeffs1[] = {1,2,3};
    int coeffs2[] = {4,5,6,7};
    
    
    Polynomial pol1(2,coeffs1);
    Polynomial pol2(3,coeffs2);
    
    int value = pol1(2);
    
    std::cout<<value<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<pol1<<std::endl;

    
    
    
    
}
