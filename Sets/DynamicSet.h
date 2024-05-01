#include <iostream>


class DynamicSet{
    
private:
    static const unsigned elementsInBucket = sizeof(uint8_t) * 8;
    unsigned maxNum = 0;
    uint8_t* buckets;
    unsigned bucketsCount = 0;
    
    
    unsigned getBucketIndex(unsigned num) const;
    unsigned getBitIndex(unsigned nun) const;
    
    void copy(const DynamicSet& other);
    void destroy();
    void move(DynamicSet&& other);
    
    
public:
    DynamicSet() = default;
    DynamicSet(unsigned maxNum);
    DynamicSet(const DynamicSet& other);
    DynamicSet(DynamicSet&& other);
    ~DynamicSet();
    DynamicSet& operator=(const DynamicSet& other);
    DynamicSet& operator=(DynamicSet&& other);
    
    unsigned getMaxNum() const;
    
    void add(unsigned num);
    bool contains(unsigned num) const;
    void remove(unsigned num);
    void print() const;
    
    
};
