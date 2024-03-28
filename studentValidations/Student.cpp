#include <stdio.h>
#include "Student.h"
#include <cstring>
#include <iostream>


const char* Student::getName() const{
    return this->name;
}

int Student::getAge() const{
    return this->age;
}



bool isSmallLetter(char ch)
{
    return ch >= 'a' && ch <= 'z';
}
bool isCapitalLetter(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}
bool containsOnlySmallChars(const char* str)
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++)
    {
        if (!isSmallLetter(str[i]))
            return false;
    }
    return true;
}

bool isValidAge(int age){
    
    return age >= MIN_AGE && age <= MAX_AGE;
}

bool isValidName(const char* name)
{
    if (name == nullptr){
        return false;
    }
    
    
    
    size_t nameLen = strlen(name);
    
    
    if (nameLen <= MIN_NAME_LEN || nameLen >= MAX_NAME_LEN)
        return false;
    
    
        if (!isCapitalLetter(*name))
            return false;
    
        for(int i = 1;i<nameLen;i++){
            if(!isSmallLetter(name[i])){
                return false;
            }
        }
        return true;
    }


void Student::setName(const char* name){
    
    if(isValidName(name)){
        std::strcpy(this->name, name);
    }
    else{

        std::strcpy(this->name,"Unknown");
    }
    
}

void Student::setAge(int age){
    if(isValidAge(age)){
        this->age = age;
    }
    else{
        this->age = 5;
    }
}

Student::Student(const char* name,int age){
    setName(name);
    setAge(age);
}

void Student::printPerson() const{
    std::cout<<"Name: " << name << " " << "is " << age << " " << "years old." << std::endl;
}
