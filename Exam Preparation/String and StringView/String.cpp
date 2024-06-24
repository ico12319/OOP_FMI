#include <stdio.h>
#include "String.h"




static unsigned roundPowerOfTwo(unsigned v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v << 4;
    v |= v << 8;
    v |= v << 16;
    v++;
    return v;
    
}

static unsigned dataToAlloc(unsigned len){
    return std::max(roundPowerOfTwo(len),16u);
}

String::String(){
    this->capacity = 8;
    this->data = new char[this->capacity];
    this->length = 0;
}

String::String(const char* data){
    this->capacity = dataToAlloc(std::strlen(data));
    this->data = new char[this->capacity];
    std::strcpy(this->data, data);
    this->length = std::strlen(data);
}

String::String(const String& other){
    copy(other);
}

String::String(String&& other){
    move(std::move(other));
}

void String::copy(const String& other){
    this->data = new char[other.capacity];
    std::strcpy(this->data, other.data);
    this->length = other.length;
}

void String::move(String&& other){
    this->data = other.data;
    other.data = nullptr;
    this->length = other.length;
    this->capacity = other.capacity;
    other.capacity = other.length = 0;
}

void String::destroy(){
    delete[]data;
    data = nullptr;
}

String::~String(){
    destroy();
}


void String::resize(unsigned newCap){
    char* temp = new char[newCap + 1];
    std::strcpy(temp, data);
    delete[]data;
    data = temp;
    this->capacity = newCap;
}

const char* String::c_str() const{
    return data;
}

size_t String::len() const{
    return length;
}

String::String(size_t capacity){
    this->capacity = dataToAlloc(capacity);
    this->data = new char[this->capacity];
    this->length = 0;
    this->data[0] = '\0';
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

String& String::operator+=(const String& other){
    if(len() + other.len() + 1 > capacity)
        resize(capacity * 2);
    std::strncat(this->data, other.data, other.length);
    return *this;
}

const char& String::operator[](size_t index) const{
    if(index > length)
        throw std::invalid_argument("Index out of bounds");
    return data[index];
}

char String::operator[](size_t index){
    if(index > length)
        throw std::invalid_argument("Index out of bounds");
    return data[index];
}


String operator+(const String& lhs,const String& rhs){
    String res(lhs);
    res+=rhs;
    return res;
}

std::ostream& operator<<(std::ostream& os,const String& obj){
    return os << obj.data;
}

std::istream& operator>>(std::istream& is,String& obj){
    char buff[1024];
    is >> buff;
    size_t buffSize = std::strlen(buff);
    if(buffSize > obj.getCapacity())
        obj.resize(obj.getCapacity() * 2);
    
    std::strcpy(obj.data, buff);
    obj.length = buffSize;
    return is;
}


bool operator==(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) == 0);
}

bool operator!=(const String& lhs,const String& rhs){
    return !(lhs==rhs);
}

bool operator<(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) < 0);
}

bool operator>(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) > 0);
}

bool operator<=(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) <= 0);
}

bool operator>=(const String& lhs,const String& rhs){
    return (std::strcmp(lhs.c_str(),rhs.c_str()) >= 0);
}


size_t String::getCapacity() const{
    return capacity;
}
