#include <stdio.h>
#include "ImmutableString.h"

StringPool ImmutableString::pool;


size_t ImmutableString::length()const{
    return this->len;
}

const char& ImmutableString::operator[](size_t index) const{
    return this->data[index];
}

const char* ImmutableString::c_str()const{
    return this->data;
}

ImmutableString::ImmutableString(const char* data){
    this->data = pool.getAllocatedString(data);
    this->len = std::strlen(data);
}


ImmutableString::ImmutableString(const ImmutableString& other){
    copy(other);
}

void ImmutableString::destroy(){
    pool.releaseString(this->data);
    this->data = nullptr;
}

ImmutableString::~ImmutableString(){
    destroy();
}

void ImmutableString::copy(const ImmutableString& other){
    this->data = pool.getAllocatedString(other.data);
    this->len = other.len;
}


std::ostream& operator<<(std::ostream& os, const ImmutableString& str){
    return os<<str.c_str();
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}


bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs==rhs);
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) <= 0);
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs>=rhs);
}


bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) >= 0);
}


bool operator<(const ImmutableString& lhs, const ImmutableString& rhs){
    return !(lhs<=rhs);
}


