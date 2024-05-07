#include <stdio.h>
#include "SortedStringPool.h"


SortedStringPool::SortedStringPool(){
    this->capacity = 8;
    this->stringCount = 0;
    this->lStrings = new LittleString*[this->capacity] {nullptr};
}

void SortedStringPool::resize(unsigned newCap){
    LittleString** newArr = new LittleString*[newCap];
    this->capacity = newCap;
    for(int i = 0;i<stringCount;i++){
        newArr[i] = lStrings[i];
    }
    delete [] this->lStrings;
    this->lStrings = newArr;
}

void SortedStringPool::destroy(){
    for(int i = 0;i<stringCount;i++){
        if(lStrings[i]->getRefCount() == 0){
            delete lStrings[i];
        }
        else{
            lStrings[i]->decrementRefCount();
        }
    }
    delete[] lStrings;
}

void SortedStringPool::copy(const SortedStringPool& other){
    this->capacity = other.capacity;
    this->stringCount = other.stringCount;
    
    lStrings = new LittleString*[other.capacity]{nullptr};
    for(int i = 0;i<other.capacity;i++){
        this->lStrings[i] = other.lStrings[i];
        this->lStrings[i]->incrementRefCount();
    }
}

void SortedStringPool::move(SortedStringPool&& other){
    this->lStrings = other.lStrings;
    other.lStrings = nullptr;
    
    this->capacity = other.capacity;
    other.capacity = 0;
    
    this->stringCount = other.stringCount;
    other.stringCount = 0;
}

SortedStringPool::SortedStringPool(const SortedStringPool& other){
    copy(other);
}

SortedStringPool::SortedStringPool(SortedStringPool&& other){
    move(std::move(other));
}

SortedStringPool& SortedStringPool::operator=(const SortedStringPool& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

SortedStringPool& SortedStringPool::operator=(SortedStringPool&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


SortedStringPool::~SortedStringPool(){
    destroy();
}


void SortedStringPool::addString(const char* str){
    if(std::strlen(str) > 64){
        throw std::invalid_argument("The string is too long!");
    }
    
    int lastStrCmpRes = -1;
    int currIndex = stringCount - 1;
    
    
    while(currIndex >= 0 && (lastStrCmpRes = std::strcmp(str, lStrings[currIndex]->getStr())) < 0){
        lStrings[currIndex + 1] = lStrings[currIndex];
        currIndex--;
    }
    
    if(currIndex + 1 > 0 && lastStrCmpRes == 0){
        lStrings[currIndex + 1] = lStrings[currIndex];
    }
    else{
        lStrings[currIndex + 1] = new LittleString(str);
    }
    lStrings[currIndex + 1]->incrementRefCount();
    stringCount++;
    
}


void SortedStringPool::removeString(size_t index){
    if(index > stringCount){
        throw std::invalid_argument("Out of bounds!");
    }
    
    if(lStrings[index]->getRefCount() == 0){
        delete lStrings[index];
    }
    else{
        lStrings[index] -> decrementRefCount();
    }
    
    for(int i = index;i<stringCount - 1;i++){
        lStrings[i] = lStrings[i+1];
    }
    
    stringCount--;
}


bool SortedStringPool::contains(const char* str) const{
    int start = 0;
    int end = stringCount - 1;
    
    int res = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        int strCmpRes = std::strcmp(str,lStrings[mid]->getStr());
        
        if(strCmpRes == 0){
            res = mid;
            end = mid - 1;
        }
        else if(strCmpRes < 0){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return (res != -1);
}


void SortedStringPool::printCollection() const{
    
    for(int i = 0;i<stringCount;i++){
        std::cout<<lStrings[i]->getStr()<<" ";
    }
    
    std::cout<<std::endl;
}
