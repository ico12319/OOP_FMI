#include "Student.h"
#include <fstream>


class StudentDatabase{
    
private:
    Student* students;
    size_t studentsCount;
    
    void copy(const StudentDatabase& other);
    void destroy();
    void move(StudentDatabase&& other);
    
    
public:
    StudentDatabase();
    StudentDatabase(const Student* students,size_t studentsCount);
    StudentDatabase(const StudentDatabase& other);
    StudentDatabase(StudentDatabase&& other);
    StudentDatabase& operator=(const StudentDatabase& other);
    StudentDatabase& operator=(StudentDatabase&& other);
    ~StudentDatabase();
    void writeStudentsToDatabse(std::ofstream& ofs) const;
    void readStudentsFromDatabase(std::ifstream& ifs);
    void printDatabase() const;
    
    
    
};
