#include <stdio.h>
#include "Set.h"


static size_t getFileSize(std::ifstream& ifs){
    size_t curr = ifs.tellg();
    ifs.seekg(0,std::ios::end);
    size_t fileSize = ifs.tellg();
    ifs.seekg(curr);
    return fileSize;
}


Set::Set(){
    this->N = 8;
    this->buckets = new uint8_t[N];
}

Set::Set(size_t N){
    bucketsCount = N / elementsInBuckets + 1;
    this->buckets = new uint8_t[bucketsCount];
    this->N = N;
}

Set::Set(const Set& other){
    copy(other);
}

Set::Set(Set&& other){
    move(std::move(other));
}

Set::~Set(){
    destroy();
}

Set& Set::operator=(const Set& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

Set& Set::operator=(Set&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

void Set::destroy(){
    delete[]buckets;
    buckets = nullptr;
}

void Set::copy(const Set& other){
    this->buckets = new uint8_t[other.bucketsCount];
    for(int i = 0;i<bucketsCount;i++)
        this->buckets[i] = other.buckets[i];
    this->bucketsCount = other.bucketsCount;
    this->N = other.N;
}


void Set::move(Set&& other){
    this->buckets = other.buckets;
    other.buckets = nullptr;
    this->bucketsCount = other.bucketsCount;
    this->N = other.N;
    other.bucketsCount = other.N = 0;
}


void Set::add(size_t num){
    
    size_t bucketIndex = getBucketIndex(num);
    size_t bitIndex = getBitIndex(num);
    
    uint8_t mask = (1 << bitIndex);
    buckets[bucketIndex] |= mask;
}

void Set::remove(size_t num){
    size_t bucketIndex = getBucketIndex(num);
    size_t bitIndex = getBitIndex(num);
    
    uint8_t mask = (1<<bitIndex);
    buckets[bucketIndex] ^= mask;
}

bool Set::contains(size_t num) const{
    size_t bucketIndex = getBucketIndex(num);
    size_t bitIndex = getBitIndex(num);
    
    uint8_t mask = (1<<bitIndex);
    return  buckets[bucketIndex] & mask;
}

void Set::print() const{
    std::cout<<"{ ";
    for(int i = 0;i<=N;i++){
        if(contains(i)){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"}"<<std::endl;
}


size_t Set::getBitIndex(size_t num) const{
    return num % elementsInBuckets;
}

size_t Set::getBucketIndex(size_t num)const{
    return num / elementsInBuckets;
}


size_t Set::getNumbersCount() const{
    size_t count = 0;
    for(int i = 0;i<=N;i++){
        if(contains(i))
            count++;
    }
    return count;
}

