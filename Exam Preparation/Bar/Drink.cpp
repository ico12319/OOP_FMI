#include <stdio.h>
#include "Drink.h"

Drink::Drink(const char* name,double price){
    std::strcpy(this->name, name);
    this->price = price;
}



const char* Drink::getName() const{
    return name;
}

