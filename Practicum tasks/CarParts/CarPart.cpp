#include <stdio.h>
#include "CarPart.h"


void CarPart::copy(const CarPart& other){
    this->iD = other.iD;
    this->manifName = new char[std::strlen(other.manifName) + 1];
    std::strcpy(this->manifName, other.manifName);
    this->description = new char[std::strlen(other.description) + 1];
    std::strcpy(this->description, other.description);
}

void CarPart::move(CarPart&& other){
    this->iD = other.iD;
    other.iD = 0;
    
    this->manifName = other.manifName;
    other.manifName = nullptr;
    
    this->description = other.description;
    other.description = nullptr;
}

CarPart::CarPart(const CarPart& other){
    copy(other);
}

CarPart::CarPart(CarPart&& other){
    move(std::move(other));
}

CarPart& CarPart::operator=(const CarPart& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

CarPart& CarPart::operator=(CarPart&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}


CarPart::~CarPart(){
    destroy();
}

const char* CarPart::getManifName() const{
    return this->manifName;
}


CarPart::CarPart(unsigned iD,const char* manifName,const char* description){
    this->iD = iD;
    this->manifName = new char[std::strlen(manifName) + 1];
    std::strcpy(this->manifName,manifName);
    this->description = new char[std::strlen(description) + 1];
    std::strcpy(this->description, description);
}

unsigned CarPart::getId() const{
    return this->iD;
}

const char* CarPart::getDescription() const{
    return this->description;
}


std::ostream& operator<<(std::ostream& os,const CarPart& obj){
    return os<<obj.getId()<<" by "<<obj.getManifName()<<" - " << obj.getDescription();
}


void CarPart::destroy(){
    delete[]this->manifName;
    this->manifName = nullptr;
    
    delete[]this->description;
    this->description = nullptr;
}
