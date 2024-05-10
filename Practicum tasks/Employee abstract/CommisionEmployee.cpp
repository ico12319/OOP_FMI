#include <stdio.h>
#include "CommisionEmployee.h"


CommisionEmployee::CommisionEmployee(const char* name,double salary,size_t commision) : Employee(name,salary){
    this->commision = commision;
}


double CommisionEmployee::calculateSalary(){
    salary = salary + (salary * commision);
    return salary;
}


std::ostream& operator<<(std::ostream& os,const CommisionEmployee& obj){
    os << (const Employee&) obj;
    os << "Commision: " << obj.commision << std::endl;
    
    return os;
}
