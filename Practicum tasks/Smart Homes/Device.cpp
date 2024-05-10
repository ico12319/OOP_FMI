#include <stdio.h>
#include "Device.h"


Device::Device(const char* name,const char* manifacturer){
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    
    this->manifacturer = new char[std::strlen(manifacturer) + 1];
    std::strcpy(this->manifacturer, manifacturer);
}

Device::Device(const Device& other){
    copy(other);
}

Device::Device(Device&& other){
    move(std::move(other));
}

Device::~Device(){
    destroy();
}

void Device::destroy(){
    delete[]name;
    name = nullptr;
    
    delete[]manifacturer;
    manifacturer = nullptr;
}

void Device::move(Device&& other){
    this->name = other.name;
    other.name = nullptr;
    
    this->manifacturer = other.manifacturer;
    other.manifacturer = nullptr;
}

void Device::copy(const Device& other){
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
    
    this->manifacturer = new char[std::strlen(other.name) + 1];
    std::strcpy(this->manifacturer, other.manifacturer);
}


void Device::printDetails() const{
    std::cout<<"Name: " << name <<std::endl;
    std::cout<<"Manifactured by: " << manifacturer << std::endl;
}
