#include <stdio.h>
#include "Bar.h"


Bar::Bar(){
    this->capacity = 8;
    this->drinks = new Drink*[this->capacity];
    this->count = 0;
}

Bar::Bar(const Bar& other){
    copy(other);
}

Bar::Bar(Bar&& other){
    move(std::move(other));
}

Bar& Bar::operator=(const Bar& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Bar& Bar::operator=(Bar&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

void Bar::destroy(){
    for(int i = 0;i<count;i++)
        delete drinks[i];
    delete[]drinks;
}

void Bar::copy(const Bar& other){
    this->drinks = new Drink*[other.capacity];
    for(int i = 0;i<other.count;i++){
        this->drinks[i] = other.drinks[i]->clone();
    }
    this->count = other.count;
    this->capacity = other.capacity;
}


void Bar::move(Bar&&  other){
    this->drinks = other.drinks;
    other.drinks = nullptr;
    this->count = other.count;
    this->capacity = other.capacity;
    other.count = other.capacity = 0;
}


void Bar::resize(size_t newCap){
    Drink** temp = new Drink*[newCap];
    for(int i = 0;i<count;i++)
        temp[i] = drinks[i]->clone();
    delete[]drinks;
    drinks = temp;
    this->capacity = newCap;
}

void Bar::addDrink(Drink* drink){
    if(count == capacity)
        resize(capacity * 2);
    
    drinks[count] = drink;
    count++;
}


void Bar::removeDrink(size_t index){
    for(size_t i = index;i<count - 1;i++){
        drinks[i] = drinks[i+1];
    }
    count--;
}

void Bar::printBar() const{
    for(int i = 0;i<count;i++)
        drinks[i]->print();
}

bool Bar::containsDrink(Drink* drink) const{
    for(int i = 0;i<count;i++){
        if((std::strcmp(drinks[i]->getName(), drink->getName()) == 0) && drinks[i]->getType() == drink->getType()){
            return true;
        }
    }
    return false;
}

DrinkType Bar::getType(size_t index) const{
    if(index > count)
        throw std::invalid_argument("Index out of bounds!");
    return drinks[index]->getType();
}


Bar::~Bar(){
    destroy();
}
