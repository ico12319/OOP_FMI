#include <stdio.h>
#include "Conjunction.h"


Conjunction::Conjunction(const Expression* left,const Expression* right) : BinaryOperation(left, right){}

bool Conjunction::eval(const BooleanInterpretation& interp) const{
    return left->eval(interp) && right->eval(interp);
}

Expression* Conjunction::clone() const{
    return new Conjunction(left->clone(),right->clone());
}
