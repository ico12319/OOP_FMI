#include <stdio.h>
#include "GraduatedStudent.h"
#include <cstring>
#include <iostream>


const char* GraduatedStudent::getName() const{
    return this->name;
}

const int* GraduatedStudent::getGrades() const{
    return this->grades;
}

int GraduatedStudent::getGradesCount() const{
    return this->gradesCount;
}

const char* GraduatedStudent::getQuoute() const{
    return this->quote;
}

void GraduatedStudent::setName(const char* name){
    if(name == nullptr || name == this->name){
        return;
    }
    
    delete [] this->name;
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}


void GraduatedStudent::setGrades(const int* grades,int gradesCount){
    if(grades == nullptr || grades == this->grades){
        return;
    }
    delete [] this->grades;
    
    this->grades = new int[gradesCount];
    for(int i = 0;i<gradesCount;i++){
        this->grades[i] = grades[i];
    }
    this->gradesCount = gradesCount;
}

void GraduatedStudent::setQuote(const char* quote){
    if(quote == nullptr || std::strlen(quote) > 30){
        return;
    }
    
    std::strcpy(this->quote,quote);
}

GraduatedStudent::GraduatedStudent(const char* name,const int* grades,int gradesCount,const char* quote){
    
    setName(name);
    setGrades(grades, gradesCount);
    setQuote(quote);
}

void GraduatedStudent::copyFrom(const GraduatedStudent& other){
    
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
    
    this->grades = new int[other.gradesCount];
    for(int i = 0;i<other.gradesCount;i++){
        this->grades[i] = other.grades[i];
    }
    this->gradesCount = other.gradesCount;
    
    std::strcpy(this->quote, other.quote);
}

void GraduatedStudent::free(){
    delete[]name;
    delete[]grades;
    
    
    name = nullptr;
    grades = nullptr;
    gradesCount = 0;
    std::strcpy(quote, "Undefined");
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& other){
    copyFrom(other);
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    
    return *this;
}

GraduatedStudent::~GraduatedStudent(){
    free();
}


void GraduatedStudent::printStudent() const{
    
    std::cout<<"Name: " << name << " " << "with grades -> ";
    for(int i = 0;i<gradesCount;i++){
        std::cout<<grades[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"And had this quote: " <<quote<<std::endl;
}

