#include <stdio.h>
#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const char* name,int age,const char* const *subjects,size_t subjectsCount):Person(name,age){
    
    this->subjects = new char*[subjectsCount];
    for(int i = 0;i<subjectsCount;i++){
        this->subjects[i] = new char[std::strlen(subjects[i]) + 1];
        std::strcpy(this->subjects[i],subjects[i]);
    }
    this->subjectsCount = subjectsCount;
}

void Teacher::copy(const Teacher& other){
    this->subjects = new char*[other.subjectsCount];
    for(int i = 0;i<other.subjectsCount;i++){
        this->subjects[i] = new char[std::strlen(other.subjects[i]) + 1];
        std::strcpy(this->subjects[i], other.subjects[i]);
    }
    this->subjectsCount = other.subjectsCount;
}

void Teacher::move(Teacher&& other){
    this->subjectsCount = other.subjectsCount;
    other.subjectsCount = 0;
    
    this->subjects = other.subjects;
    other.subjects = nullptr;
}

void Teacher::destroy(){
    for(int i = 0;i<subjectsCount;i++){
        delete[] subjects[i];
    }
    delete[] subjects;
}


Teacher::~Teacher(){
    destroy();
}

Teacher::Teacher(const Teacher& other) : Person(other){
    copy(other);
}


Teacher::Teacher(Teacher&& other) : Person(std::move(other)){
    move(std::move(other));
}

Teacher& Teacher::operator=(const Teacher& other){
    if(this!=&other){
        Person::operator=(other);
        destroy();
        copy(other);
    }
    return *this;
}

Teacher& Teacher::operator=(Teacher&& other){
    if(this!=&other){
        Person::operator=(std::move(other));
        destroy();
        move(std::move(other));
    }
    
    return *this;
}



void Teacher::printTeacher() const{
    std::cout<<getName()<<" " << getAge() << std::endl;
    for(int i = 0;i<subjectsCount;i++){
        std::cout<<subjects[i]<<" ";
    }
    
    std::cout<<std::endl;
}
