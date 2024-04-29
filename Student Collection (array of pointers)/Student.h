#include "String.h"


class Student{
    
private:
    String name;
    unsigned age;
    
public:
    Student(const String& name, unsigned age);
    const String& getName() const;
    
    void printStudent() const;
    
};
