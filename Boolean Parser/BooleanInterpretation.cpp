#include <stdio.h>
#include "BooleanInterpretation.h"


BooleanInterpretation::BooleanInterpretation(const bool* variablesValues){
    for(int i = 0;i<ALPHABET_SIZE;i++){
        this->variablesValues[i] = variablesValues[i];
    }
}

bool BooleanInterpretation::getVariableValue(char var) const{
    return variablesValues[var - 'a'];
}

void BooleanInterpretation::setVariableValue(char var,bool value){
    variablesValues[var - 'a'] = value;
}
