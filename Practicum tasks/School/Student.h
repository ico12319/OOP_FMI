#include "Person.h"


class Student : private Person{
    
private:
    int fn = 0;
    
public:
    Student() = default;
    Student(const char* name,int age,int fn);
    
    int getFn() const;
};
