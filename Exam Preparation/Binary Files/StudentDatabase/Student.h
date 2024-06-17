#include <iostream>


const int MAX_NAME_LEN = 25;

class Student{
private:
    char name[MAX_NAME_LEN + 1];
    int age;
    bool isMale;
    
public:
    Student();
    Student(const char* name,int age,bool isMale);
    const char* getName() const;
    int getAge() const;
    bool getIsMale() const;

};
