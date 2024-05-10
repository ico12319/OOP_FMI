#include "Employee.h"

class HourlyEmployee : public Employee{
    
private:
    size_t overTime;
    
public:
    HourlyEmployee(const char* name,double salary,size_t overTime);
    
    
    double calculateSalary() override;
    
    friend std::ostream& operator<<(std::ostream& os,const HourlyEmployee& obj);
    
};
