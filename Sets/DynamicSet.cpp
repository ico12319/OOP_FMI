#include <stdio.h>
#include "DynamicSet.h"



unsigned DynamicSet::getMaxNum() const{
    return this->maxNum;
}

DynamicSet::DynamicSet(unsigned maxNum){
    this->bucketsCount = maxNum / elementsInBucket + 1;
    this->buckets = new uint8_t[bucketsCount]{};
    this->maxNum = maxNum;
}

unsigned DynamicSet::getBucketIndex(unsigned num) const{
    return num / elementsInBucket;
}

unsigned DynamicSet::getBitIndex(unsigned num) const{
    return num % elementsInBucket;
}

void DynamicSet::copy(const DynamicSet& other){
    this->maxNum = other.maxNum;
    this->bucketsCount = other.bucketsCount;
    this->buckets = new uint8_t[other.bucketsCount]{};
    for(int i = 0;i<other.bucketsCount;i++){
        this->buckets[i] = other.buckets[i];
    }
}

DynamicSet::DynamicSet(const DynamicSet& other){
    copy(other);
}

void DynamicSet::destroy(){
    delete[]buckets;
    buckets = nullptr;
}

DynamicSet::~DynamicSet(){
    destroy();
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
}

void DynamicSet::move(DynamicSet&& other){
    this->maxNum = other.maxNum;
    other.maxNum = 0;
    
    this->buckets = other.buckets;
    other.buckets = nullptr;
    
    this->bucketsCount = other.bucketsCount;
    other.bucketsCount = 0;
}

DynamicSet::DynamicSet(DynamicSet&& other){
    move(std::move(other));
}

DynamicSet& DynamicSet::operator=(DynamicSet&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}

void DynamicSet::add(unsigned num){
    
    int bukcketIndex = getBucketIndex(num);
    int bitIndex = getBitIndex(num);
    
    uint8_t mask = 1<<bitIndex;
    
    buckets[bukcketIndex] |= mask;
}


bool DynamicSet::contains(unsigned num) const{
    
    int bucketIndex = getBucketIndex(num);
    int bitIndex = getBitIndex(num);
    
    uint8_t mask = 1 << bitIndex;
    
    return (buckets[bucketIndex] & mask);
    
}

void DynamicSet::remove(unsigned num){
    
    
    int bucketIndex = getBucketIndex(num);
    int bitIndex = getBitIndex(num);
    
    uint8_t mask = 1<<bitIndex;
    
    buckets[bucketIndex] ^= mask;
}

void DynamicSet::print() const{
    std::cout<<"{ ";
    for(int i = 0;i<maxNum;i++){
        if(contains(i)){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"}";
    std::cout<<std::endl;
}
