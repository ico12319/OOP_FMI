#include <stdio.h>
#include "StringPool.h"
#include "iostream"


StringPool::StringPool(){
    capacity = 8;
    stringCount = 0;
    stringRecords = new StringRecord[capacity];
}


int StringPool::findAllocatedString(const char* data){
    
    for(int i = 0;i<stringCount;i++){
        if(std::strcmp(stringRecords[i].str,data) == 0){
            return i;
        }
    }
    return -1;
}


void StringPool::resize(size_t newCap){
    StringRecord* newRecords = new StringRecord[newCap];
    for(int i = 0;i<stringCount;i++){
        newRecords[i] = stringRecords[i];
    }
    
    delete [] stringRecords;
    stringRecords = newRecords;
}

void StringPool::removeString(size_t index){
    std::swap(stringRecords[index], stringRecords[stringCount-1]);
    delete[] stringRecords[stringCount - 1].str;
    
}

unsigned StringPool::allocateNewString(const char* data){
    if(stringCount == capacity){
        resize(stringCount * 2);
    }
    
    unsigned firstFreeIndex = stringCount++;
    stringRecords[firstFreeIndex].str = new char[std::strlen(data) + 1];
    std::strcpy(stringRecords[firstFreeIndex].str,data);
    stringRecords[firstFreeIndex].refCount = 0;
    
    return firstFreeIndex;
}

const char* StringPool::getAllocatedString(const char* str){
    int index = findAllocatedString(str);
    
    
    if(index != -1){
        stringRecords[index].refCount++;
        return stringRecords[index].str;
    }
    else{
        unsigned indexNewRecord = allocateNewString(str);
        stringRecords[indexNewRecord].refCount++;
        return stringRecords[indexNewRecord].str;
    }
}


void StringPool::releaseString(const char* str){
    int index = findAllocatedString(str);
    
    stringRecords[index].refCount--;
    
    if(stringRecords[index].refCount == 0){
        removeString(index);
    }
}
