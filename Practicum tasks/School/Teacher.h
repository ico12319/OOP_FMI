#include "Person.h"


class Teacher : private Person{
    
private:
    char** subjects;
    size_t subjectsCount;
    
    
    void copy(const Teacher& other);
    void destroy();
    void move(Teacher&& other);
    
public:
    Teacher() = default;
    Teacher(const char* name, int age, const char* const *subjects,size_t sibjectsCount);
    Teacher(const Teacher& other);
    Teacher(Teacher&& other);
    Teacher& operator=(const Teacher& other);
    Teacher& operator=(Teacher&& other);
    ~Teacher();
    
    
    void printTeacher() const;
    
    
};
