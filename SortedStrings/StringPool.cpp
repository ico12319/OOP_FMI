#include <stdio.h>
#include "StringPool.h"


StringPool::StringPool(){
    this->capacity = 8;
    this->stringCount = 0;
    this->records = new StringRecord[this->capacity];
}

void StringPool::resize(unsigned newCap){
    this->capacity = newCap;
    StringRecord* newRecords = new StringRecord[newCap];
    for(int i = 0;i<stringCount;i++){
        newRecords[i] = records[i];
    }
    
    delete[] records;
    records = newRecords;
}

int StringPool::findRecord(const char* str) const{
    
    int start = 0;
    int end = stringCount - 1;
    int res = -1;
    
    while(start <= end){
        int mid = start + (end - start) / 2;
        
        int cmpRes = std::strcmp(str, records[mid].str);
        
        if(cmpRes == 0){
            res = mid;
            end = mid - 1;
        }
        else if(cmpRes < 0){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return res;
    
}

void SortedStringPool::removeRecord(size_t index){
    for(int i = index;i<stringCount - 1;i++){
        records[i] = records[i + 1];
    }
}


const char* StringPool::getAllocatedString(const char* str){
    
    if(stringCount == capacity){
        resize(capacity * 2);
    }
    int index = findRecord(str);
    if(index != - 1){
        records[index].refCount++;
        return records[index].str;
        
    }
    else{
        int cmpRes = -1;
        int currInd = stringCount - 1;
        while(currInd >= 0 && (cmpRes = std::strcmp(str,records[currInd].str)) < 0){
            records[currInd + 1] = records[currInd];
            currInd--;
        }
        
        if(currInd + 1 == 0 || cmpRes != 0){
            records[currInd + 1].str = new char[std::strlen(str) + 1];
            std::strcpy(records[currInd + 1].str, str);
            records[currInd + 1].refCount++;
            stringCount++;
        }
        
        return records[currInd + 1].str;
    }
}



void SortedStringPool::releaseString(const char* str){
    int index = findRecord(str);
    
    if(records[index] .refCount == 1){
        delete[] records[index].str;
        removeRecord(index);
        stringCount--;
    }
    else{
        records[index].refCount--;
    }
}
