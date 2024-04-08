//  Hristo Partenov,
//  Information Systems,
//  Sofia University
//  FN -> ...
//  Custom implementation of string class in c++

#pragma once 
#include <fstream>

const size_t BUFFER_SIZE = 1024;

class Istring{
private:
    char* data = nullptr;
    size_t length = 0;
    
    void copy(const Istring& other);
    void destroy();

    explicit Istring(size_t size);
public:
    // Constructors:
    Istring();
    Istring(const char* data);
    Istring(const Istring& other);
    Istring& operator=(const Istring& other);
    ~Istring();

    // Getters: 
    size_t getLength() const;
    const char* c_str() const;
    
    // Setter:
    void setData(const char* data);
        
    void reverse();
    bool isPalindrome() const;

    // Operators:
    const char& operator[](int index) const;
    char& operator[](int index);
    Istring& operator+=(const Istring& other);
    Istring& operator-=(const Istring& other);
    Istring& operator()(int replicateCount);

    // Streams:
    friend std::ostream& operator<<(std::ostream& os,const Istring& str);
    friend std::istream& operator>>(std::istream& is, Istring& str);
};

Istring operator+(const Istring& lhs, const Istring& rhs);
bool operator==(const Istring& lhs,const Istring& rhs);
bool operator!=(const Istring& lhs,const Istring& rhs);
