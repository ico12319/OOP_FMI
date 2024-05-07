#include "StringPool.h"
#include <fstream>


class ImmutableString{
private:
    const char* data;
    size_t len;
    static StringPool pool;
    
    void copy(const ImmutableString& other);
    void destroy();
    
public:
    ImmutableString(const char* data);
    ImmutableString(const ImmutableString& other);
    ~ImmutableString();
    
    const char* c_str() const;
    size_t length() const;
    const char& operator[](unsigned index) const;
};

std::ostream& operator<<(std::ostream& os, const ImmutableString& str);
bool operator==(const ImmutableString& lhs,const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
