#include <iostream>
#include <fstream>

class Set{
    
private:
    uint8_t* buckets;
    const size_t elementsInBuckets = 8 * sizeof(uint8_t);
    size_t N;
    size_t bucketsCount;
    
    void copy(const Set& other);
    void move(Set&& other);
    void destroy();
    size_t getBucketIndex(size_t num) const;
    size_t getBitIndex(size_t num) const;
public:
    Set();
    Set(size_t N);
    Set(const Set& other);
    Set(Set&& other);
    Set& operator=(const Set& other);
    Set& operator=(Set&& other);
    ~Set();
    
    void add(size_t num);
    void remove(size_t num);
    bool contains(size_t num) const;
    void print() const;
    size_t getNumbersCount() const;
    void writeInBinaryFile(std::ofstream& ofs) const;
    void readFromBinaryFile(std::ifstream& ifs);
};
