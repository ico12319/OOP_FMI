#include <stdio.h>
#include "Student.h"


Student::Student(){
    std::strcpy(this->name, "Uknown");
    this->age = 0;
    this->isMale = true;
}


Student::Student(const char* name,int age,bool isMale){
    std::strcpy(this->name, name);
    this->age = age;
    this->isMale = isMale;
}


const char* Student::getName() const{
    return this->name;
}

int Student::getAge() const{
    return this->age;
}

bool Student::getIsMale() const{
    return isMale;
}
