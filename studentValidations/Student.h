


const int MIN_AGE = 5;
const int MAX_AGE = 90;

const int MAX_NAME_LEN = 20;
const int MIN_NAME_LEN = 2;

class Student{
private:
    char name[MAX_NAME_LEN + 1];
    int age = 5;
    
public:
    
    Student() = default;
    Student(const char* name,int age);
    
    const char* getName() const;
    int getAge() const;
    
    void setName(const char* name);
    void setAge(int age);
    
    
    void printPerson() const;
    
};
