#include <stdio.h>
#include "AlcoholDrink.h"


void AlcoholDrink::setPercentAlcohol(size_t percentAlcohol){
    if(percentAlcohol < 5 || percentAlcohol > 98){
        return;
    }
    
    this->percentAlcohol = percentAlcohol;
}

AlcoholDrink::AlcoholDrink(const char* name, size_t quantity, size_t percentAlcohol) : Drink(name,quantity){
    setPercentAlcohol(percentAlcohol);
}


