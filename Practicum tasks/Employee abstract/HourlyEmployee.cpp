#include <stdio.h>
#include "HourlyEmployee.h"


HourlyEmployee::HourlyEmployee(const char* name,double salary,size_t overTime) : Employee(name,salary){
    this->overTime = overTime;
}

double HourlyEmployee::calculateSalary(){
    salary = 40 * 4 * salary + (salary * 0.5 * overTime);
    return salary;
}


std::ostream& operator<<(std::ostream& os,const HourlyEmployee& obj){
    os << (const Employee&) obj;
    os << "OverTime: " << obj.overTime << std::endl;
    
    return os;
    
}
