#include "stdint.h"
const int QUOTE_MAX_LEN = 30;


class GraduatedStudent{
    
private:
    char* name = nullptr;
    int* grades = nullptr;
    int gradesCount = 0;
    char quote[QUOTE_MAX_LEN + 1] = "Not defined";
    
    void copyFrom(const GraduatedStudent& other);
    void free();
    
public:
    GraduatedStudent() = default;
    GraduatedStudent(const char* name,const int* grades,int gradesCount,const char* quote);
    GraduatedStudent(const GraduatedStudent& other);
    GraduatedStudent& operator=(const GraduatedStudent& other);
    ~GraduatedStudent();
    
    
    const char* getName() const;
    const int* getGrades() const;
    const char* getQuoute() const;
    int getGradesCount() const;
    
    void setName(const char* name);
    void setGrades(const int* grades,int gradesCount);
    void setQuote(const char* quote);
    
    void printStudent() const;
    
    
    
    
    
    
    
};
