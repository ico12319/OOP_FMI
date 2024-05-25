#include <iostream>
#include "MaximumPartialFunction.hpp"


struct ExampleFunction {
    int operator()(int x) const {
        return x * x;
    }
};

struct AnotherExampleFunction {
    int operator()(int x) const {
        return x + 10;
    }
};


int main(int argc, const char * argv[]) {
  
    ExcludedPoints excluded("BinarenTest.dat");
    ExampleFunction exampleFunc;
    AnotherExampleFunction anotherFunc;
    
    PartialFunctionByCriteria<ExampleFunction, Pair> partialFunc(exampleFunc, excluded);
    
    PartialFunctionByCriteria<AnotherExampleFunction, Pair> partialFunc2(anotherFunc, excluded);
    PartialFunction<Pair>* functions[] = { &partialFunc, &partialFunc2 };
    size_t functionCount = sizeof(functions) / sizeof(functions[0]);
    MaximumPartialFunction<Pair> max ((const PartialFunction<Pair>**)functions, functionCount);
    
    int testPoint = 2;
    if (max.isDefined(testPoint)) {
        std::cout << "Max f(" << testPoint << ") = " << max(testPoint) << std::endl;
    } else {
        std::cout << "Max f(" << testPoint << ") is not defined." << std::endl;
    }
}
