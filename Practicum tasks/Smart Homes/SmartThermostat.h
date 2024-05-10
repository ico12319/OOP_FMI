#include "SmartLight.h"


class SmartThermostat : public Device{
    
private:
    int currentTemperature;
    int wantedTemperature;
    
public:
    SmartThermostat(const char* name,const char* manifacturer,int currentTemperature,int wantedTemperature);
    
    void turnOn() const override;
    void turnOff() const override;
    void printDetails() const override;
};
