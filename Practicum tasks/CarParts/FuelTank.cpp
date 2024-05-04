#include <stdio.h>
#include "FuelTank.h"


FuelTank::FuelTank(double cap){
    this->capacity = cap;
    this->fullness = cap;
}


void FuelTank::addFuel(double value){
    fullness+=value;
    if(value > capacity || value + fullness > capacity || fullness > capacity){
        fullness = capacity;
        return;
    }
}


void FuelTank::useFuel(double value){
    if(value > fullness || value > capacity){
        throw insufficient_fuel_error();
    }
    
    fullness-=value;
}


double FuelTank::getCap() const{
    return this->capacity;
}


double FuelTank::getLevel() const{
    return this->fullness;
}
