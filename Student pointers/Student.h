#include <iostream>

class Student{
    
private:
    char* name;
    int fn;
    char* major;
    
    void copy(const Student& other);
    void destroy();
    void move(Student&& other);
    
public:
    Student(const char* name, int fn, const char* major);
    Student(const Student& other);
    Student(Student&& other);
    ~Student();
    Student& operator=(const Student& other);
    Student& operator=(Student&& other);
    
    const char* getName() const;
    const char* getMajor()const;
    
    void printStudent() const;
    
};
