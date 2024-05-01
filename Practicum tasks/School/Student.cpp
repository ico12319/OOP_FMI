#include <stdio.h>
#include "Student.h"


Student::Student(const char* name,int age,int fn) : Person(name,age){
    this->fn = fn;
}

int Student::getFn() const{
    return this->fn;
}


