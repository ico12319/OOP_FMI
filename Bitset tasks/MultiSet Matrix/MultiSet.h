
#include <iostream>


constexpr int elementsInBucket = sizeof(uint8_t) * 8;

class MultiSet{
    
private:
    int maxNum = 0;
    int bitsNeeded = 0;
    int bucketsCount = 0;
    uint8_t** buckets;
    size_t maxOccur = 0;
    
    void copy(const MultiSet& other);
    void destroy();
    void move(MultiSet&& other);
    
public:
    MultiSet() = default;
    MultiSet(int maxNum,int bitsNeeded);
    MultiSet(const MultiSet& other);
    MultiSet(MultiSet&& other);
    ~MultiSet();
    MultiSet& operator=(const MultiSet& other);
    MultiSet& operator=(MultiSet&& other);
    
    int getBucketIndex(int num) const;
    int getBitIndex(int num) const;
    
    void add(int num);
    bool contains(int num) const;
    int countOccur(int num) const;
    void print() const;
    
};
