#include <iostream>
#include <fstream>

class String{

private:
    char* data;
    size_t currLen;
    size_t capacity;
    
    void resize(size_t newCap);
    void move(String&& other);
    void copy(const String& other);
    void destroy();
    explicit String(size_t len);
    
public:
    String();
    String(const char* data);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();
    
    String& operator+=(const String& other);
    const char& operator[](size_t index) const;
    char& operator[](size_t index);
    friend String operator+(const String& lhs,const String& rhs);
    
    const char* c_str() const;
    size_t length() const;
    friend std::istream& operator>>(std::istream& is,String& obj);
};

std::ostream& operator<<(std::ostream& os,const String& obj);
bool operator==(const String& lhs,const String& rhs);
bool operator!=(const String& lhs,const String& rhs);
bool operator>(const String& lhs,const String& rhs);
bool operator<(const String& lhs,const String& rhs);
