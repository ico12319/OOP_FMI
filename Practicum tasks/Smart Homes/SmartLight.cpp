#include <stdio.h>
#include "SmartLight.h"


SmartLight::SmartLight(const char* name,const char* manifacturer,short brightnessLevel) : Device(name, manifacturer){
    this->brightnessLevel = brightnessLevel;
}

void SmartLight::turnOn() const{
    std::cout<<"The smart light is now turned on!"<<std::endl;
}

void SmartLight::turnOff()const{
    std::cout<<"The smart light is now turned off!"<<std::endl;
}

void SmartLight::printDetails() const{
    Device::printDetails();
    std::cout<<"Brightness level is currenlty set on: " << brightnessLevel << "%" << std::endl;
    
}
