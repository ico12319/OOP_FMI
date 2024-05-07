#include "Student.h"

class StudentArray{
    
private:
    Student** students;
    size_t studentsCount;
    size_t capacity;
    
    void copy(const StudentArray& other);
    void move(StudentArray&& other);
    void destroy();
    void resize(unsigned newCap);
    
public:
    StudentArray();
    StudentArray(const StudentArray& other);
    StudentArray(StudentArray&& other);
    ~StudentArray();
    StudentArray& operator=(const StudentArray& other);
    StudentArray& operator=(StudentArray&& other);
    
    void pushBack(const Student& other);
    void pushBack(Student&& other);
    
    void pushFront(const Student& other);
    void pushFront(Student&& other);
    
    void push(const Student& other);
    
    
    void pushAt(int ind,const Student& other);
    void pushAt(int ind,Student&& other);
    
    
    bool contains(int ind) const;
    int firstFreeIndex() const;
    Student getBack() const;
    Student getFront() const;
    size_t size() const;
    Student at(int index) const;
    void print() const;
    
    
};
