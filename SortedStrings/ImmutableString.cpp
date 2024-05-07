#include <stdio.h>
#include "ImmutableString.h"

StringPool ImmutableString ::pool;

ImmutableString::ImmutableString(const char* data){
    this->data = pool.getAllocatedString(data);
    this->len = std::strlen(data);
}

void ImmutableString::copy(const ImmutableString& other){
    this->data = pool.getAllocatedString(other.data);
    this->len = other.len;
}

void ImmutableString::destroy(){
    pool.releaseString(this->data);
}

const char* ImmutableString::c_str() const{
    return this->data;
}

size_t ImmutableString::length() const{
    return this->len;
}

const char& ImmutableString::operator[](unsigned index) const{
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str){
    return os<<str.c_str();
}

ImmutableString::~ImmutableString(){
    destroy();
}

ImmutableString::ImmutableString(const ImmutableString& other){
    copy(other);
}



bool operator==(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) == 0);
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs == rhs);
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) <= 0);
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs <= rhs);
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) >= 0);
}


bool operator<(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs >= rhs);
}
