#include "String.h"

class StringView{
private:
    const char* _begin;
    const char* _end;
    
public:
    StringView(const char* begin,const char* end);
    StringView(const String& obj);
    StringView(const char* data);
    StringView substr(size_t from,size_t len) const;
    const char& operator[](size_t index) const;
    size_t length() const;
    friend std::ostream& operator<<(std::ostream& os,const StringView& obj);
    
};
