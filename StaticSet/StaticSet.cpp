#include <stdio.h>
#include "StaticSet.h"
#include <iostream>



unsigned StaticSet::getBucketIndex(unsigned n) const{
    
    return n / BUCKET_SIZE;
}


unsigned StaticSet::getBitIndex(unsigned n) const{
    return n % BUCKET_SIZE;
}



void StaticSet::add(unsigned number){
    
    if(number > MAX_NUM){
        return;
    }
    
    unsigned bucketIndex = getBucketIndex(number);
    unsigned bitIndex = getBitIndex(number);
    
    uint8_t mask = 1 << bitIndex;
    
    buckets[bucketIndex] |= mask;
}

void StaticSet::remove(unsigned number){
    
    unsigned bucketIndex = getBucketIndex(number);
    unsigned bitIndex = getBitIndex(number);
    
    
    uint8_t mask = 1 << bitIndex;
    
    mask = ~mask;
    
    buckets[bucketIndex] &= mask;
    
}


bool StaticSet::contains(unsigned number) const{
    
    unsigned bucketIndex = getBucketIndex(number);
    unsigned bitIndex = getBitIndex(number);
    
    uint8_t mask = 1 << bitIndex;
    unsigned copy = buckets[bucketIndex];
    
    return (copy & mask)!=0;
}

void StaticSet::print() const {
    
    
    std::cout << "{ ";
    for(int i = 0;i<=MAX_NUM;i++){
        if(contains(i)){
            std::cout<<i<<" ";
        }
    }
    std::cout<<" }"<<std::endl;
    
}
