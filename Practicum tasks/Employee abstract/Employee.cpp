#include <stdio.h>
#include "Employee.h"


Employee::Employee(const char* name,double salary){
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    
    this->salary = salary;
}

Employee::Employee(const Employee& other){
    copy(other);
}

Employee::Employee(Employee&& other){
    move(std::move(other));
}

Employee::~Employee(){
    destroy();
}

void Employee::destroy(){
    delete[]name;
    name = nullptr;
}

void Employee::copy(const Employee& other){
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
    
    this->salary = other.salary;
}

void Employee::move(Employee&& other){
    this->name = other.name;
    other.name = nullptr;
    
    this->salary = other.salary;
    other.salary = 0;
}


Employee& Employee::operator=(const Employee& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Employee& Employee::operator=(Employee&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
    
}


std::ostream& operator<<(std::ostream& os,const Employee& obj){
    os << "Name: " << obj.name << std::endl;
    os << "Salary: " << obj.salary << std::endl;
    return os;
}


double Employee::getSalary() const{
    return this->salary;
}
