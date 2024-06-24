#include <stdio.h>
#include "StringView.h"

StringView::StringView(const char* begin,const char* end) : _begin(begin),_end(end){}

StringView::StringView(const char* data) : StringView(data,data + std::strlen(data)){}

StringView::StringView(const String& obj) : StringView(obj.c_str()){}

StringView StringView::substr(size_t from, size_t len) const{
    if(_begin + from + len > _end)
        throw std::invalid_argument("Out of bounds!");
    return StringView(_begin + from,_begin + from + len);
}

size_t StringView::length() const{
    return _end - _begin;
}

const char& StringView::operator[](size_t index) const{
    if(index > length())
        throw std::invalid_argument("Out of bounds");
    return _begin[index];
}

std::ostream& operator<<(std::ostream& os,const StringView& obj){
    const char* iter = obj._begin;
    while(iter != obj._end){
        os<<*iter;
        iter++;
    }
    return os;
}
