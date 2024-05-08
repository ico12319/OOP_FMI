#include "String.h"


class Student{
    
private:
    String name;
    unsigned fn;
    unsigned year;
    
public:
    Student(const String& name,unsigned fn,unsigned year);
    String getName() const;
    unsigned getFn() const;
    unsigned getYear() const;
    
    void printStudent() const;
    
};
bool operator==(const Student& lhs,const Student& rhs);

