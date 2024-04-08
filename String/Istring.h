//  Hristo Partenov,
//  Information Systems,
//  Sofia University
//  FN -> 0MI0700218
//  Custom implementation of string class in c++

#pragma once
#include <fstream>

const size_t BUFFER_SIZE = 1024; //size of the buffer that we are using for the redefenition of the operator >>.

class Istring{
private:
    char* data = nullptr;
    size_t length = 0;
    
    void copy(const Istring& other); //copy function used in the copy constructor.
    void destroy(); // destroy function which is used in the destructor.

    explicit Istring(size_t size); //constructor which allocates memory.
    
    
public:
    // Constructors:
    Istring(); //default constructor
    Istring(const char* data); //constructor with parameters.
    Istring(const Istring& other); //copy constructor
    Istring& operator=(const Istring& other); //redefenition of operator =
    ~Istring(); //destructor

    // Getters:
    size_t getLength() const;
    const char* c_str() const; //synonym for getData
    
    // Setter:
    void setData(const char* data);
        
    void reverse(); //reverse the string
    bool isPalindrome() const; //checks whether the given string is a palindrome.
    bool contains(const char* str) const; //checks whether a certain string is a substring of the given string.
    void clear(); //clears the string but keeps the already allocated memory

    // Operators that are changing our object.
    const char& operator[](int index) const; //method that returns the symbol that is situated in the wanted index. We can't change it!
    char& operator[](int index); //method that returns the symbol that is situated in the wanted index. We can change it!
    Istring& operator+=(const Istring& other); //method that changes the given string by concatenating it with the so called other string.
    Istring& operator-=(const Istring& other); //method that removes a certain string from the given one if contained.
    Istring& operator()(int replicateCount); //method that replicates the string count times.

    // Streams:
    friend std::ostream& operator<<(std::ostream& os,const Istring& str); //method that allows the user to use <<
    friend std::istream& operator>>(std::istream& is, Istring& str); //method that allows the user to use >>
};
//Operators that are not changing our object.
Istring operator+(const Istring& lhs, const Istring& rhs); //the same method as += but without changing the given string.Working with a copy.
Istring operator-(const Istring& lhs,const Istring& rhs); //the same method as -= but without changing the given string.Working with a copy.
bool operator==(const Istring& lhs,const Istring& rhs); //method that checks whether two strings are equal.
bool operator!=(const Istring& lhs,const Istring& rhs); //method that checks whether two strings are different.
