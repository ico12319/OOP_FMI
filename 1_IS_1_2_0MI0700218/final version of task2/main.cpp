#include "ModifiableIntegerFunction.h"


//  test the task using release build, may not compile using debug release


int16_t nor(int16_t x) {
    return x;
}

int16_t nor2(int16_t y){
    return y;
}


int16_t dummy(int16_t x) {
    return x + 2;
}

int16_t square(int16_t x) {
    return x * x;
}

int16_t cube(int16_t x) {
    return x * x * x;
}



int16_t linear5(int16_t x) {
    return 3 * x + 5;
}

int16_t linear8(int16_t x) {
    return 3 * x + 5;
}




int main() {
    
    
    //ModifiableIntegerFunction func1(dummy);
    //ModifiableIntegerFunction func2(square);
    //func2.excludePoint(8);
    //std::cout<<func2.isExcluded(8);

    //func1+=func2;//should return 14 -> (3+2) + (3^2) = 5 + 9 = 14 (for value 3)
    //std::cout<<func1(3)<<std::endl;
    //func1-=func2; // should return -4 -> (3+2) - (3^2) = 5 - 9 = -4 (for value 3)
    //std::cout<<func1(3)<<std::endl;
    
    //ModifiableIntegerFunction func3 = func1 + func2; // (5+2) + (5^2) = 7 + 25 = 32
    //ModifiableIntegerFunction func3 = func1 - func2; // (5+2) - (5^2) = 7 - 25 = - 18
    //std::cout<<func3(5)<<std::endl;
    
    //std::cout<<func1.isSurjective()<<std::endl; // should return true
    //std::cout<<func1.isInjective()<<std::endl; // should retun false
    //std::cout<<func1.isBijective()<<std::endl; // should return false
    
    //func2.excludePoint(3);
    //std::cout<<func2.isSurjective()<<std::endl;// should return false
    //std::cout<<func2.isInjective()<<std::endl; //should return false
    //std::cout<<func2.isBijective()<<std::endl; //should return false
    
    //ModifiableIntegerFunction funckiq1(linear5);
    //ModifiableIntegerFunction funkciq2(linear8);
    
    //bool flag1 = funckiq1 || funkciq2;
    
    //std::cout<<flag1<<std::endl; //shoudl return true
    
    //ModifiableIntegerFunction funckiq3(square);
    //ModifiableIntegerFunction funkciq4(cube);
    //std::cout<<(funckiq3 || funkciq4)<<std::endl; // should return false
    
    
    //ModifiableIntegerFunction func5 = func1 * func2; // f1(f2(x)) -> f1(9) -> 9 + 2 = 11
    //std::cout<<func5(3)<<std::endl; //should return 11
    //std::cout<<func5(2)<<std::endl; //shoudl return 6
    
    
    
    //ModifiableIntegerFunction func20(dummy);
    //ModifiableIntegerFunction func21 = func20 ^ 3; // f(f(f(x))) -> f(f(5)) -> f(7) -> 9
    //std::cout<<func21(3)<<std::endl; // should return 9
    
    
    //ModifiableIntegerFunction func6(nor); // the arr is too big and the searching algorithm is not optimal so be ready to wait (10-12 seconds) before seeing the result
    //std::cout<<func6.isSurjective()<<std::endl;;//should return true
    //std::cout<<func6.isInjective()<<std::endl; // should return true
    //std::cout<<func6.isBijective()<<std::endl; //shold return true
    
    
    //ModifiableIntegerFunction func1(linear5);
    //func1.printGraph(0, 20, 0, 20);
    
    
    
    
    

}
