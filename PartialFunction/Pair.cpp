#include <stdio.h>
#include "Pair.h"


Pair::Pair(bool isDefined,int value){
    setIsDefined(isDefined);
    setValue(value);
}

bool Pair::getIsDefined() const{
    return isDefined;
}

int Pair::getValue() const{
    return value;
}

void Pair::setValue(int value){
    this->value = value;
}

void Pair::setIsDefined(bool isDefined){
    this->isDefined = isDefined;
}

std::ostream& operator<<(std::ostream& os, const Pair& pair) {
    os << "(" << pair.isDefined << ", " << pair.value << ")";
    return os;
}

