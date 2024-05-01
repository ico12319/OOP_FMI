#include <stdio.h>
#include "Person.h"
#include <iostream>


const char* Person::getName() const{
    return this->name;
}

void Person::setName(const char* name){
    if(name == nullptr || this->name == name){
        return;
    }
    
    delete[]this->name;
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

Person::Person(const char* name, int age){
    setName(name);
    this->age = age;
}

void Person::destroy(){
    delete[] this->name;
    this->name = nullptr;
}

Person::~Person(){
    destroy();
}

void Person::copy(const Person& other){
    this->age = other.age;
    
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
}

Person::Person(const Person& other){
    copy(other);
}

void Person::move(Person&& other){
    this->age = other.age;
    other.age = 0;
    
    this->name = other.name;
    other.name = nullptr;
}

Person::Person(Person&& other){
    move(std::move(other));
}

Person& Person::operator=(const Person& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Person& Person::operator=(Person&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

int Person::getAge() const{
    return this->age;
}


