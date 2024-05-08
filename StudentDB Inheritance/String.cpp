#include <stdio.h>
#include "String.h"

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

static size_t dataToAlloc(size_t len){
    return std::max(getRoundPowerOfTwo(len + 1),16u);
}


String::String(const char* data){
    this->capacity = dataToAlloc(std::strlen(data));
    this->currLen = std::strlen(data);
    this->data = new char[this->capacity];
    std::strcpy(this->data, data);
}

String::String(size_t len){
    this->capacity = dataToAlloc(len);
    this->currLen = 0;
    this->data = new char[this->capacity];
    this->data[0] = '\0';
}

String::String() : String(""){}


void String::copy(const String& other){
    this->capacity = other.capacity;
    this->currLen = other.currLen;
    this->data = new char[other.currLen];
    std::strcpy(this->data, other.data);
}

void String::move(String&& other){
    this->data = other.data;
    other.data = nullptr;
    
    this->capacity = other.capacity;
    other.capacity = 0;
    
    this->currLen = other.currLen;
    other.currLen = 0;
}

void String::destroy(){
    delete[]this->data;
    this->data = nullptr;
}

String::~String(){
    destroy();
}

String::String(const String& other){
    copy(other);
}

String::String(String&& other){
    move(std::move(other));
}

String& String::operator=(const String& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

String& String::operator=(String&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

const char* String::c_str() const{
    return this->data;
}

size_t String::length() const{
    return this->currLen;
}

void String::resize(size_t newCap){
    char* temp = new char[newCap + 1];
    std::strcpy(temp, data);
    delete[]data;
    data = temp;
    capacity = newCap;
}


const char& String::operator[](size_t index) const{
    if(index > currLen){
        throw std::invalid_argument("Out of bounds!");
    }
    return data[index];
}

char& String::operator[](size_t index){
    if(index > currLen){
        throw std::invalid_argument("Out of bounds!");
    }
    return data[index];
}

String& String::operator+=(const String& other){
    if(length() + other.length() + 1 > capacity){
        resize(dataToAlloc(length() + other.length()));
    }
    
    std::strncat(this->data, other.data, other.length());
    this->currLen = length() + other.length();
    return *this;
}



String operator+(const String& lhs,const String& rhs){
    String res(lhs.length() + rhs.length());
    res+=lhs;
    res+=rhs;
    return res;
}



bool operator==(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) == 0);
}

bool operator!=(const String& lhs,const String& rhs){
    return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os,const String& obj){
    return os << obj.c_str();
}

std::istream& operator>>(std::istream& is,String& obj){
    char buff[1024];
    is >> buff;
    size_t buffSize = std::strlen(buff);
    if(buffSize > obj.capacity){
        obj.resize(dataToAlloc(buffSize));
    }
    
    std::strcpy(obj.data, buff);
    obj.currLen = buffSize;
    return is;
    
}


bool operator>(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) > 0);
}


bool operator<(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) < 0);
}
