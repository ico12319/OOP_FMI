#include <stdio.h>
#include "Drink.h"
#include <iostream>



static bool isCapital(char s){
    return s >= 'A' && s<= 'Z';
}


const char* Drink::getName() const{
    return this->name;
}


size_t Drink::getQuantity() const{
    return this->quantity;
}

void Drink::setName(const char* name){
    if(name == nullptr || this->name == name || !isCapital(*name)){
        return;
    }
    
    size_t size = std::strlen(name);
    this->name = new char[size + 1];
    std::strcpy(this->name, name);
}


void Drink::setQuantity(size_t quantity){
    if(quantity < 200 || quantity > 1000){
        return;
    }
    
    this->quantity = quantity;
}

Drink::Drink(const char* name, size_t quantity){
    setName(name);
    setQuantity(quantity);
}


void Drink::copy(const Drink& other){
    this->quantity = other.quantity;
    
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name,other.name);
}

void Drink::destroy(){
    delete[] this->name;
    this->name = nullptr;
    this->quantity = 0;
}

Drink::~Drink(){
    destroy();
}

Drink::Drink(const Drink& other){
    copy(other);
}

void Drink::move(Drink&& other){
    this->quantity = other.quantity;
    other.quantity = 200;
    
    this->name = other.name;
    other.name = nullptr;
}


Drink::Drink(Drink&& other){
    move(std::move(other));
}

Drink& Drink::operator=(const Drink& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
}

Drink& Drink::operator=(Drink&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}

void Drink::printDrink() const{
    std::cout<<name<<std::endl;
}


