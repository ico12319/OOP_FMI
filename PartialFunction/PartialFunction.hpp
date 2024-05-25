#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Pair.h"
#include "IncludedPoints.h"


template <class T>

class PartialFunction{
    
public:
    virtual T operator() (int x) const = 0;
    virtual bool isDefined(int point) const = 0;
    virtual ~PartialFunction() = default;
    virtual PartialFunction<T>* clone() const = 0;
};


