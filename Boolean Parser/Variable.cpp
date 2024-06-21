#include <stdio.h>
#include "Variable.h"

bool Variable::eval(const BooleanInterpretation& interp) const{
    return interp.getVariableValue(symbol);
}

Expression* Variable::clone() const{
    return new Variable(symbol);
}


Variable::Variable(char symbol){
    this->symbol = symbol;
}
