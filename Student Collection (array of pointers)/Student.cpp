#include <stdio.h>
#include "Student.h"
#include "iostream"


Student::Student(const String& name, unsigned age){
    this->name = name;
    this->age = age;
}

const String& Student::getName() const{
    return this->name;
}


void Student::printStudent() const{
    std::cout<<name<< "-> " << age<<std::endl;
}
