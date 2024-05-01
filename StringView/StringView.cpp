#include <stdio.h>
#include "StringView.h"


StringView::StringView(const char* begin, const char* end){
    _begin = begin;
    _end = end;
}

StringView::StringView(const char* str){
    _begin = str;
    _end = str + std::strlen(str);
}

StringView::StringView(const String& other){
    _begin = other.c_str();
    _end = _begin + other.length();
}

size_t StringView::len() const{
    return _end - _begin;
}

const char& StringView::operator[](size_t index) const{
    return _begin[index];
}

StringView StringView::substring(size_t from, size_t len) const{
    if(_begin + from + len > _end){
        throw std::length_error("Error!");
    }
    
    return StringView(_begin + from, _begin + from + len);
}

std::ostream& operator<<(std::ostream& os, const StringView& obj){
    const char* iter = obj._begin;
    
    while(iter!=obj._end){
        os<<*iter;
        iter++;
    }
    return os;
}

