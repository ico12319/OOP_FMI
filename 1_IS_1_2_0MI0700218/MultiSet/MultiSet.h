#include <iostream>
// done with the help of Михаел Михайлов -> 0MI0700220, Жоземир Кушев -> 8MI0700284, Виктор Миланов -> 0MI0700270
class MultiSet {
private:
    
    uint8_t* buckets = nullptr;
    unsigned bucketsCount = 0;
    unsigned n = 0;
    unsigned k = 0;
    const unsigned elementsInBucket = sizeof(uint8_t) * 8;

    void free();
    void copyFrom(const MultiSet& other);


    unsigned getBucketIndex(unsigned number) const;
    bool isInOneBucket(unsigned startIndex) const;
    unsigned getNumberStartIndex(unsigned num) const;
    
    
    
public:
    
    MultiSet() = default;
    MultiSet(unsigned n, unsigned k);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);
    ~MultiSet();


    void add(unsigned num);
    void printLikeInMemory() const;
    void printMultiSet() const;
    unsigned countOfNumber(unsigned num) const;
    void complement(int num);
    bool contains(uint8_t num) const;
    
    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);
    
    
    
    friend MultiSet intersectionOfSets(const MultiSet& lhs, const MultiSet& rhs);
    friend MultiSet differenceOfSets(const MultiSet& lhs, const MultiSet& rhs);
};
