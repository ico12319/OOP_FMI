#include <stdio.h>
#include "SetByString.h"


void SetByString::extractNums(){
    
    size_t size = std::strlen(data);
    for(int i = 0;i<size;i++){
        if(data[i] != '\0' && data[i] == ' '){
            continue;
        }
        
        int currNum = 0;
        while(data[i] != ' ' && data[i] != '\0'){
            if(data[i] >= '0' && data[i] <= '9'){
                currNum = currNum * 10 + (data[i] - '0');
            }
            i++;
        }
        if(currNum != 0){
            add(currNum);
        }
    }
}


SetByString::SetByString(unsigned maxNum,const char* data) : DynamicSet(maxNum){
    size_t size = std::strlen(data);
    this->data = new char[size + 1];
    std::strcpy(this->data, data);
    extractNums();
}

void SetByString::copy(const SetByString& other){
    size_t size = std::strlen(other.data);
    
    this->data = new char[size + 1];
    
    std::strcpy(this->data, other.data);
}

SetByString::SetByString(const SetByString& other) : DynamicSet(other){
    copy(other);
}

SetByString& SetByString::operator=(const SetByString& other){
    if(this!=&other){
        DynamicSet::operator=(other);
        destroy();
        copy(other);
    }
    return *this;
}

void SetByString::destroy(){
    delete[] this->data;
}

SetByString::~SetByString(){
    destroy();
}

void SetByString::move(SetByString&& other){
    this->data = other.data;
    other.data = nullptr;
}

SetByString::SetByString(SetByString&& other){
    move(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other){
    if(this!=&other){
        DynamicSet::operator=(std::move(other));
        destroy();
        move(std::move(other));
    }
    return *this;
}

void SetByString::setAt(int index, char s){
    data[index] = s;
    extractNums();
}

void SetByString::print() const{
    return DynamicSet::print();
}

void SetByString::add(unsigned num){
    DynamicSet::add(num);
}

void SetByString::remove(unsigned num){
    DynamicSet::remove(num);
}

bool SetByString::contains(unsigned num) const{
    return DynamicSet::contains(num);
}
