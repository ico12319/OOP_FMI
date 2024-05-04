#include "insufficinet_fuel_error.h"


class FuelTank{
    
private:
    double capacity;
    double fullness;
    
public:
    FuelTank() = default;
    FuelTank(double cap);
    
    void useFuel(double value);
    void addFuel(double value);
    
    double getCap() const;
    double getLevel() const;
};
