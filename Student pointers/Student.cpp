#include <stdio.h>
#include "Student.h"


Student::Student(const char* name,int fn,const char* major){
    
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name,name);
    
    this->fn = fn;
    
    this->major = new char[std::strlen(major) + 1];
    std::strcpy(this->major,major);
    
}

void Student::copy(const Student& other){
    
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name,other.name);
    
    this->fn = other.fn;
    
    this->major = new char[std::strlen(other.major) + 1];
    std::strcpy(this->major,other.major);
}

void Student::destroy(){
    delete[]this->name;
    this->name = nullptr;
    
    delete[]this->major;
    this->major = nullptr;
}


void Student::move(Student&& other){
    this->name = other.name;
    other.name = nullptr;
    
    this->fn = other.fn;
    other.fn = 0;
    
    this->major = other.major;
    other.major = nullptr;
}

Student::Student(const Student& other){
    copy(other);
}

Student::Student(Student&& other){
    move(std::move(other));
}

Student& Student::operator=(const Student& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Student& Student::operator=(Student&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

Student::~Student(){
    destroy();
}

const char* Student::getName() const{
    return this->name;
}

void Student::printStudent() const{
    
    std::cout<<name<<" -> " << fn << " -> " << getMajor() << std::endl;
}

const char* Student::getMajor() const{
    return this->major;
}
