#pragma once
#include "stdint.h"
#include <iostream>

const int MAX_NUM = 1023;
const int MAX_NUMBERS_COUNT = MAX_NUM + 1;
const int BUCKET_SIZE = sizeof(uint8_t);
const int BUCKETS_COUNT = (MAX_NUMBERS_COUNT / BUCKET_SIZE) + 1;


class StaticSet{
    
private:
    uint8_t buckets[BUCKETS_COUNT] = {0};
    unsigned getBucketIndex(unsigned n) const;
    unsigned getBitIndex(unsigned n) const;
    
public:
    
    StaticSet() = default;
    
    void add(unsigned number);
    void remove(unsigned number);
    
    bool contains(unsigned number) const;
    void print() const;
    
    
    
};


