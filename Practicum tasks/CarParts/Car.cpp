#include <stdio.h>
#include "Car.h"

Car::Car(const FuelTank& tank,const Engine& engine,const Tyres* tyres,const Accumulator& accum,double km,double weght){
    this->tank = tank;
    this->engine = engine;
    for(int i = 0;i<MAX_TYRES;i++){
        this->tyres[i] = tyres[i];
    }
    this->accum = accum;
    this->km = km;
    this->weight = weght;
}


void Car::drive(double kmDriven){
    
    double fuelReq = kmDriven;
    if(fuelReq > tank.getLevel()){
        throw insufficient_fuel_error();
    }
    
    km+=kmDriven;
    tank.useFuel(fuelReq);
}


void Car::print() const{
    
    std::cout<<"Current tank level -> " << tank.getLevel()<<std::endl;
    std::cout<<"Km driven -> " << km << std::endl;
    std::cout<<"The car weights -> " << weight << std::endl;
    std::cout<<"Car's engine: ";
    std::cout<< engine;
    
    std::cout<<"Car's tyres:"<<std::endl;
    for(int i = 0;i<MAX_TYRES;i++){
        std::cout<< tyres[i];
    }
    
    std::cout<<"Car's accumulator: ";
    std::cout<<accum;
    
}



Car* dragRace(Car* car1,Car* car2){
    
    double distance = 0.4;
    double fuelRequired = distance;
    
    if(car1->tank.getLevel() < fuelRequired && car2->tank.getLevel() < fuelRequired){
        return nullptr;
    }
    else if(car1->tank.getLevel() < fuelRequired){
        return car2;
    }
    else if(car2->tank.getLevel() < fuelRequired){
        return car1;
    }
    
    car1->km += distance;
    car2->km += distance;
    
    car1->tank.useFuel(fuelRequired);
    car2->tank.useFuel(fuelRequired);
    
    double ratio1 = car1->weight / car1->engine.getHorsePower();
    double ratio2 = car2->weight / car2->engine.getHorsePower();
    
    if(ratio1 > ratio2){
        return car1;
    }
    else if(ratio1 < ratio2){
        return car2;
    }
    else{
        return nullptr;
    }
    
}


Engine Car::getEngine() const{
    return this->engine;
}
