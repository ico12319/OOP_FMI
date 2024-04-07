#include <stdio.h>
#include "Istring.h"
#include <cstring>


size_t Istring::getLength() const{
    return this->length;
}


const char* Istring::getData() const{
    return this->data;
}

void Istring::copy(const Istring& other){
    
    this->data = new char[other.length + 1];
    std::strcpy(this->data,other.data);
    
    this->length = other.length;
    
}

void Istring::destroy(){
    delete[] this->data;
    
    this->length = 0;
}

Istring& Istring::operator=(const Istring& other){
    if(this != &other){
        destroy();
        copy(other);
    }
    
    return *this;
}

Istring::Istring(const Istring& other){
    copy(other);
}


Istring::~Istring(){
    destroy();
}

void Istring::setData(const char* data){
    
    if(!data || this->data == data){
        return;
    }
    
    delete[] this->data;
    
    this->length = std::strlen(data);
    this->data = new char[this->length + 1];
    std::strcpy(this->data, data);
}




void Istring::reverse(){
    
    
    for(int i = 0;i<length/2;i++){
        std::swap(this->data[i],this->data[length - i -1]);
    }
    
    
}

Istring::Istring(const char* data){
    setData(data);
}


const char& Istring::operator[](int index) const{
    return this->data[index];
}

char& Istring::operator[](int index){
    return this->data[index];
}

Istring& Istring::operator+=(const Istring& other){
    
    size_t newLen = this->length + other.length;
    
    char* newStr = new char[newLen + 1];
    
    std::strcpy(newStr, this->data);
    std::strcat(newStr, other.data);
    
    delete[]this->data;
    this->data = newStr;
    this->length = newLen;
    
    return * this;
    
}


std::ostream& operator<<(std::ostream& os,const Istring& str){
    
    for(int i = 0;i<str.length;i++){
        os<<str[i];
    }
    return os;
    
}

Istring operator+(const Istring& lhs,const Istring& rhs){
    
    Istring copy(lhs);
    copy+=rhs;
    
    return copy;
}

bool operator==(const Istring& lhs,const Istring& rhs){
    
    if(lhs.getLength() != rhs.getLength()){
        return false;
    }
    
    for(int i = 0;i<lhs.getLength();i++){
        if(lhs[i] != rhs[i]){
            return false;
        }
    }
    
    return true;
    
}

bool operator!=(const Istring& lhs,const Istring& rhs){
    return !(lhs==rhs);
}


bool Istring::isPalindrome() const{
    Istring reversed(*this);
    
    reversed.reverse();
    
    return (*this==reversed);
    
}

Istring& Istring::operator()(int replicateCount){
    
    
    int ind = 0;
    size_t newSize = replicateCount * length;
    char* tempStr = new char[newSize + 1];
    
    for(int i = 0;i<newSize;i++){
        tempStr[i] = data[ind];
        if(ind == length-1){
            ind = 0;
        }
        else{
            ind++;
        }
    }
    tempStr[newSize] = '\0';
    delete[]this->data;
    this->data = tempStr;
    this->length = newSize;
    
    return *this;
    
}
