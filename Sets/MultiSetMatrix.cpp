#include <stdio.h>
#include "MultiSet.h"


void MultiSet::copy(const MultiSet& other){
    this->maxNum = other.maxNum;
    this->bitsNeeded = other.bitsNeeded;
    this->maxOccur = other.maxOccur;
    this->bucketsCount = other.bucketsCount;
    this->buckets = new uint8_t*[other.maxOccur];
    for(int i = 0;i<other.maxOccur;i++){
        this->buckets[i] = new uint8_t[other.bucketsCount];
        for(int j = 0;j<other.maxOccur;j++){
            this->buckets[i][j] = other.buckets[i][j];
        }
    }
}


void MultiSet::destroy(){
    
    for(int i = 0;i<this->bucketsCount;i++){
        delete[] buckets[i];
    }
    
    delete[] buckets;
    
    this->maxNum = 0;
    this->bucketsCount = 0;
    this->bitsNeeded = 0;
}

MultiSet::MultiSet(int maxNum,int bitsNeeded){
    
    this->bucketsCount = maxNum / elementsInBucket + 1;
    this->maxOccur = (1<<bitsNeeded) - 1;
    this->buckets = new uint8_t*[maxOccur];
    
    for(int i = 0;i<this->maxOccur;i++){
        this->buckets[i] = new uint8_t[this->bucketsCount] {0};
    }
    this->maxNum = maxNum;
    this->bitsNeeded = bitsNeeded;
}

MultiSet::MultiSet(const MultiSet& other){
    copy(other);
}

MultiSet::~MultiSet(){
    destroy();
}

MultiSet& MultiSet::operator=(const MultiSet& other){
    
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

void MultiSet::move(MultiSet&& other){
    this->maxNum = other.maxNum;
    other.maxNum = 0;
    
    this->bitsNeeded = other.bitsNeeded;
    other.bitsNeeded = 0;
    
    this->bucketsCount = other.bucketsCount;
    other.bucketsCount = 0;
    
    this->buckets = other.buckets;
    other.buckets = nullptr;
}

MultiSet::MultiSet(MultiSet&& other){
    move(std::move(other));
}

MultiSet& MultiSet::operator=(MultiSet&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}

int MultiSet::getBucketIndex(int num) const{
    return num / elementsInBucket;
}

int MultiSet::getBitIndex(int num) const{
    return num % elementsInBucket;
}

bool MultiSet::contains(int num) const{
    
    int bitIndex = getBitIndex(num);
    int bucketIndex = getBucketIndex(num);
    uint8_t mask = 1 << bitIndex;
    
    for(int i = 0;i<maxOccur;i++){
        if(buckets[i][bucketIndex] & mask){
            return true;
        }
    }
    return false;
}

int MultiSet::countOccur(int num) const{
    int count = 0;
    int bitIndex = getBitIndex(num);
    int bucketIndex = getBucketIndex(num);
    uint8_t mask = 1<<bitIndex;
    for(int i = 0;i<maxOccur;i++){
        if(buckets[i][bucketIndex] & mask){
            count++;
        }
    }
    
    return count;
}


void MultiSet::add(int num){
    if(num > maxNum){
        return;
    }
    
    int bitIndex = getBitIndex(num);
    int bucketIndex = getBucketIndex(num);
    
    uint8_t mask = 1 << bitIndex;
    for(int i = 0; i<maxOccur;i++){
        if(!(buckets[i][bucketIndex] & mask)){
            buckets[i][bucketIndex] |= mask;
            break;
        }
    }
    
}

void MultiSet::print() const{
    std::cout<<"{ ";
    for(int i = 0; i<maxNum;i++){
        if(contains(i)){
            for(int j = 0;j<countOccur(i);j++){
                std::cout<<i<<" ";
            }
        }
    }
    std::cout<<" }"<<std::endl;
}

