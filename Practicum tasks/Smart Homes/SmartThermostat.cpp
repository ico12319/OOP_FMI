#include <stdio.h>
#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(const char* name,const char* manifacturer,int currentTemperature,int wantedTemperature) : Device(name, manifacturer){
    this->currentTemperature = currentTemperature;
    this->wantedTemperature = wantedTemperature;
}

void SmartThermostat::turnOn() const{
    std::cout<<"The smart-thermostat is now turned on!"<<std::endl;
}

void SmartThermostat::turnOff() const{
    std::cout<<"The smart-thermostat is now turned off!"<<std::endl;
}

void SmartThermostat::printDetails() const{
    Device::printDetails();
    std::cout<<"Current temperature: " << currentTemperature << std::endl;
    std::cout<<"Wanted temperature: " << wantedTemperature << std::endl;
}

