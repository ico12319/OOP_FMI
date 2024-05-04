#include "Accumulator.h"
#include "FuelTank.h"



constexpr int MAX_TYRES = 4;

class Car{
    
private:
    FuelTank tank;
    Engine engine;
    Tyres tyres[MAX_TYRES];
    Accumulator accum;
    double km;
    double weight;
    
    
public:
    Car(const FuelTank& tank,const Engine& engine,const Tyres* tyres,const Accumulator& accum,double km,double weght);
    
    void drive(double kmDriven);
    void print() const;
    Engine getEngine() const;
    
    friend Car* dragRace(Car* car1, Car* car2);
};
