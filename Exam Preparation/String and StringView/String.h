#include <iostream>
#include <fstream>

class String{
private:
    char* data;
    size_t length;
    size_t capacity;
    
    void copy(const String& other);
    void move(String&& other);
    void destroy();
    void resize(unsigned newCapcity);
    explicit String(size_t capcity);
    size_t getCapacity() const;
    
public:
    String();
    String(const char* data);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();
    
    const char* c_str() const;
    size_t len() const;
    String& operator+=(const String& other);
    friend std::ostream& operator<<(std::ostream& os,const String& obj);
    friend std::istream& operator>>(std::istream& is,String& obj);
    const char& operator[](size_t index) const;
    char operator[](size_t index);
    friend String operator+(const String& lhs,const String& rhs);
};
bool operator==(const String& lhs,const String& rhs);
bool operator!=(const String& lhs,const String& rhs);
bool operator>=(const String& lhs,const String& rhs);
bool operator>(const String& lhs,const String& rhs);
bool operator<=(const String& lhs,const String& rhs);
bool operator<(const String& lhs,const String& rhs);


