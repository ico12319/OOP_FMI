#include "HourlyEmployee.h"


class CommisionEmployee : public Employee{
    
private:
    size_t commision;
    
public:
    CommisionEmployee(const char* name,double salary,size_t commision);
    
    double calculateSalary() override;
    friend std::ostream& operator<<(std::ostream& os,const CommisionEmployee& obj);
};
