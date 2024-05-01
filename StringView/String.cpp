#include <stdio.h>
#include "String.h"
#include <iostream>


static unsigned getRoundPowerOfTwo(unsigned num){
    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    num++;
    return num;
    
}

static unsigned getCapToAlloc(unsigned len){
    return std::max(getRoundPowerOfTwo(len + 1),16u);
}


String::String(unsigned len){
    this->currLen = 0;
    this->capacity = getCapToAlloc(len);
    this->data = new char[this->capacity];
    data[0] = '\0';
}

String::String(){
    String("");
}

String::String(const char* data){
    this->currLen = std::strlen(data);
    this->capacity = getCapToAlloc(this->currLen);
    this->data = new char[this->capacity];
    std::strcpy(this->data,data);
}

void String::destroy(){
    delete[]this->data;
    this->data = nullptr;
    this->currLen = 0;
    this->capacity = 0;
}

void String::copy(const String& other){
    this->currLen = other.currLen;
    this->capacity = other.capacity;
    
    this->data = new char[other.capacity];
    std::strcpy(this->data, other.data);
}

void String::move(String&& other){
    this->capacity = other.capacity;
    other.capacity = 0;
    this->currLen = other.currLen;
    other.currLen = 0;
    
    this->data = other.data;
    other.data = nullptr;
}

String::String(const String& other){
    copy(other);
}

String& String::operator=(const String& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

String::String(String&& other){
    move(std::move(other));
}

String& String::operator=(String&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

void String::resize(unsigned newCap){
    char* newData = new char[newCap + 1];
    std::strcpy(newData, this->data);
    delete[]this->data;
    this->data = newData;
    this->capacity = newCap;
}


String::~String(){
    destroy();
}


String& String::operator+=(const String& other){
    if(length() + other.length() + 1 > capacity){
        resize(getCapToAlloc(length() + other.length()));
    }
    
    std::strncat(this->data, other.data, other.length());
    this->currLen = length() + other.length();
    
    return *this;
}

const char& String::operator[](unsigned index) const{
    if(index > currLen){
        throw std::out_of_range("Out of bounds!");
    }
    return this->data[index];
}


char& String::operator[](unsigned index){
    if(index > currLen){
        throw std::out_of_range("Out of bounds!");
    }
    return this->data[index];
}

String operator+(const String& lhs,const String& rhs){
    String res(lhs.length() + rhs.length());
    
    res+=lhs;
    res+=rhs;
    
    return res;
}


std::ostream& operator<<(std::ostream& os,const String& obj){
    return os << obj.c_str();
}

const char* String::c_str() const{
    return this->data;
}

size_t String::length() const{
    return this->currLen;
}


unsigned String::getCap() const{
    return capacity - 1;
}

std::istream& operator>>(std::istream& is, String& obj){
    char buff[1024];
    is >> buff;
    size_t size = std::strlen(buff);
    if(size > obj.getCap()){
        obj.resize(getCapToAlloc(size));
    }
    
    std::strcpy(obj.data, buff);
    obj.currLen = size;
    
    return is;
}
