#pragma once
#include <iostream>
#include <fstream>


const unsigned BIT_ON = 1;
const unsigned BIT_OFF = 0;


class MultiSet {
   
private:
    uint8_t* buckets = nullptr;
    uint8_t bits = 0;
    unsigned maxNum = 0;


    void copy(const MultiSet& other);
    void destroy();

public:
    MultiSet() = default;
    MultiSet(unsigned maxNum, uint8_t bits);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);
    ~MultiSet();
    
    const uint8_t& operator[](int index) const;
    uint8_t& operator[](int index);

    
    void add(unsigned num);
    bool contains(unsigned num) const;
    unsigned countOcurrences(unsigned num) const;
    void print() const;
    void writeToBinary(std::ofstream& ofs);
    void readFromBinary(std::ifstream& ifs);
    void printLikeInMemory() const;
    
    
    friend MultiSet complement(const MultiSet& orig);
    friend MultiSet interSectSet(const MultiSet& lhs, const MultiSet& rhs);
    friend MultiSet diffSet(const MultiSet& lhs, const MultiSet& rhs);
    
    
};
