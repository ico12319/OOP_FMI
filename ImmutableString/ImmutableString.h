#pragma once
#include "StringPool.h"
#include <fstream>

class ImmutableString{
    
private:
    const char* data = nullptr;
    size_t len = 0;
    static StringPool pool;
    
    void copy(const ImmutableString& other);
    void destroy();
    
    explicit ImmutableString(size_t cap);
    
public:
    ImmutableString(const char* data);
    ImmutableString(const ImmutableString& other);
    ~ImmutableString();
    
    size_t length() const;
    const char& operator[](size_t index) const;
    const char* c_str() const;
    
};


std::ostream& operator<<(std::ostream& os, const ImmutableString& str);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);


