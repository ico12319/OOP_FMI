#include "Student.h"

class StudentDB{
protected:
    Student** students;
    size_t studentsCount;
    size_t capacity;
    
    void copy(const StudentDB& other);
    void destroy();
    void move(StudentDB&& other);
    void resize(size_t newCap);
    
public:
    StudentDB();
    StudentDB(const StudentDB& other);
    StudentDB(StudentDB&& other);
    StudentDB& operator=(const StudentDB& other);
    StudentDB& operator=(StudentDB&& other);
    ~StudentDB();
    
    size_t getStudentsCount() const;
    Student** getStudents() const;
    
    void add(const Student& student);
    void remove(const Student& student);
    bool find(unsigned fn) const;
    void display() const;
    
    
};
