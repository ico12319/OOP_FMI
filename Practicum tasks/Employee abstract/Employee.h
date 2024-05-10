#include <iostream>
#include <fstream>

class Employee{
    
protected:
    char* name;
    double salary;
    
    void copy(const Employee& other);
    void destroy();
    void move(Employee&& other);
    
public:
    Employee(const char* name,double salary);
    Employee(const Employee& other);
    Employee(Employee&& other);
    virtual ~Employee();
    Employee& operator=(const Employee& other);
    Employee& operator=(Employee&& other);
    
    double getSalary() const;
    
    friend std::ostream& operator<<(std::ostream& os,const Employee& obj);
    virtual double calculateSalary() = 0;
    
};
