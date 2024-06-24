#include <stdio.h>
#include "AlcoholDrink.h"

AlcoholDrink::AlcoholDrink(const char* name,double price) : Drink(name, price){}

Drink* AlcoholDrink::clone() const{
    return new AlcoholDrink(*this);
}

DrinkType AlcoholDrink::getType() const{
    return DrinkType::ALCOHOL_DRINK;
}

void AlcoholDrink::print() const{
    std::cout<<name<<" is an alcohol drink and costs: " << price<<std::endl;
}


