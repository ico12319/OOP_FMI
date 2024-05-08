#include <stdio.h>
#include "Student.h"

Student::Student(const String& name,unsigned fn,unsigned year){
    this->name = name;
    this->fn = fn;
    this->year = year;
}

String Student::getName() const{
    return this->name;
}

unsigned Student::getFn() const{
    return this->fn;
}

unsigned Student::getYear() const{
    return this->year;
}


void Student::printStudent() const{
    std::cout<<"Name: " << name << std::endl;
    std::cout<<"Faculty number: " << fn << std::endl;
    std::cout<<"Current year: " << year << std::endl;
}


bool operator==(const Student& lhs,const Student& rhs){
    return (lhs.getName() == rhs.getName() && lhs.getFn() == rhs.getFn() && lhs.getYear() == rhs.getYear());
}
