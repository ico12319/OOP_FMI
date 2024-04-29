#include "Student.h"


class StudentCollection{
    
private:
    Student** students;
    size_t currSize;
    size_t allocatedSpace;
    
    
    void copy(const StudentCollection& other);
    void destroy();
    void move(StudentCollection&& other);
    void resize(size_t newAlloc);
    
    size_t getFirstFreeIndex() const;
    
    
public:
    StudentCollection();
    StudentCollection(const StudentCollection& other);
    StudentCollection(StudentCollection&& other);
    StudentCollection& operator=(const StudentCollection& other);
    StudentCollection& operator=(StudentCollection&& other);
    ~StudentCollection();
    
    void push(const Student& student);
    const Student& at(size_t index) const;
    void pushAt(size_t index,const Student& student);
    void removeAt(size_t index);
    void setAt(const Student& student,size_t index);
    size_t getNumberInClass(const Student& student) const;
    size_t getCapacity() const;
    bool containsAt(size_t index) const;
    void print() const;
    
};
