#include <stdio.h>
#include "SmartSpeaker.h"

SmartSpeaker::SmartSpeaker(const char* name,const char* manifacturer,size_t volume) : Device(name,manifacturer){
    this->volume = volume;
}

void SmartSpeaker::turnOff() const{
    std::cout<<"The smart speaker is now tuned off!"<<std::endl;
}

void SmartSpeaker::turnOn() const{
    std::cout<<"The smart speaker is now turned on!"<<std::endl;
}

void SmartSpeaker::printDetails() const{
    Device::printDetails();
    std::cout<<"Current volume: " << volume << std::endl;
}
