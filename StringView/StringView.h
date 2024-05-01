#include "String.h"


class StringView{
    
private:
    const char* _begin;
    const char* _end;
    
    
public:
    StringView(const char* begin, const char* end);
    StringView(const String& string);
    StringView(const char* str);
    
    size_t len() const;
    const char& operator[](size_t index) const;
    
    StringView substring(size_t from, size_t len) const;
    friend std::ostream& operator<<(std::ostream& os, const StringView& obj);
    
};
