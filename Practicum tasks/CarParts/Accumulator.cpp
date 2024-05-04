#include <stdio.h>
#include "Accumulator.h"



Accumulator::Accumulator(unsigned iD,const char* manifName,const char* description,unsigned capacity,const char* batteryId) : CarPart(iD, manifName, description){
    
    this->capacity = capacity;
    this->batteryId = new char[std::strlen(batteryId) + 1];
    std::strcpy(this->batteryId, batteryId);
}

void Accumulator::copy(const Accumulator& other){
    this->capacity = other.capacity;
    this->batteryId = new char[std::strlen(other.batteryId) + 1];
    std::strcpy(this->batteryId, other.batteryId);
    
}

void Accumulator::destroy(){
    delete[]this->batteryId;
    this->batteryId = nullptr;
}

Accumulator::~Accumulator(){
    destroy();
}

Accumulator::Accumulator(const Accumulator& other) : CarPart(other){
    copy(other);
}


void Accumulator::move(Accumulator&& other){
    this->capacity = other.capacity;
    other.capacity = 0;
    this->batteryId = other.batteryId;
    other.batteryId = nullptr;
}

Accumulator::Accumulator(Accumulator&& other) : CarPart(std::move(other)){
    move(std::move(other));
}

Accumulator& Accumulator::operator=(const Accumulator& other){
    if(this!=&other){
        CarPart::operator=(other);
        destroy();
        copy(other);
    }
    
    return *this;
}

Accumulator& Accumulator::operator=(Accumulator&& other){
    if(this!=&other){
        CarPart::operator=(std::move(other));
        destroy();
        move(std::move(other));
    }
    
    return *this;
}


std::ostream& operator<<(std::ostream& os,const Accumulator& accum){
    const CarPart& part = accum;
    return os << part << " - " << accum.capacity<<" Ah."<<std::endl;
}
