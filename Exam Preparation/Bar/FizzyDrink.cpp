#include <stdio.h>
#include "FizzyDrink.h"


FizzyDrink::FizzyDrink(const char* name,double price) : Drink(name, price){}


DrinkType FizzyDrink::getType() const{
    return DrinkType::NON_ALCOHOL_DRINK;
}

Drink* FizzyDrink::clone() const{
    return new FizzyDrink(*this);
}

void FizzyDrink::print() const{
    std::cout<<name<<" is a non-alcoholic drink and costs: " << price<<std::endl;
}


