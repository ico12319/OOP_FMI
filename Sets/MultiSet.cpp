#include <stdio.h>
#include "MultiSet.h"


const uint8_t& MultiSet::operator[](int index) const{
    return buckets[index];
}

uint8_t& MultiSet::operator[](int index){
    return buckets[index];
}


void MultiSet::copy(const MultiSet& other)
{
    this->buckets = new uint8_t[other.maxNum];
    for (int i = 0; i < other.maxNum; i++) {
        this->buckets[i] = other.buckets[i];
    }

    this->bits = other.bits;
    this->maxNum = other.maxNum;
}

void MultiSet::destroy() {

    delete[] buckets;

    this->buckets = nullptr;
    this->maxNum = 0;
    this -> bits = 0;

}


MultiSet::MultiSet(unsigned maxNum, uint8_t bits)
{
    this->maxNum = maxNum;
    this->bits = bits;
    
    this->buckets = new uint8_t[maxNum]{0};
}

MultiSet::MultiSet(const MultiSet& other)
{
    copy(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

MultiSet::~MultiSet()
{
    destroy();
}

void MultiSet::add(unsigned num){
    if (num > maxNum || buckets[num] >= pow(2,bits) - 1)
        return;

    buckets[num] = -~buckets[num];
}


bool MultiSet::contains(unsigned num) const
{
    if(num > maxNum){
        return false;
    }
    return (buckets[num] | 0) != 0;
}

unsigned MultiSet::countOcurrences(unsigned num) const
{
    if(num > maxNum){
        return -1;
    }
    return buckets[num];
}



void MultiSet::print() const
{
    std::cout << "{ ";
    for (int i = 0; i <= maxNum; i++)
    {
        if (contains(i)) {
            for (int j = 0; j < buckets[i]; j++) {
                std::cout << i << " ";
            }
        }
    }

    std::cout << "}" << std::endl;
}


void MultiSet::printLikeInMemory() const{
    
    for(int i = maxNum - 1; i >= 0; i--){
        if(contains(i)){
            std::cout<<BIT_ON;
        }
        else{
            std::cout<<BIT_OFF;
        }
    }
}


MultiSet interSectSet(const MultiSet& lhs, const MultiSet& rhs){
    
    MultiSet intersection(std::min(lhs.maxNum, rhs.maxNum), std::min(lhs.bits, rhs.bits));

    int minSize = std::min(lhs.maxNum, rhs.maxNum);
    for (int i = 0; i < minSize; i++) {
        if (lhs.contains(i) && rhs.contains(i)) {
            int countInIntersection = std::min(lhs.countOcurrences(i), rhs.countOcurrences(i));
            for (int j = 0; j < countInIntersection; j++) {
                intersection.add(i);
            }
        }
    }
    return intersection;
}


MultiSet diffSet(const MultiSet& lhs, const MultiSet& rhs){
    
    MultiSet diff(lhs.maxNum,lhs.bits);
    int minSize = std::min(lhs.maxNum,rhs.maxNum);
    
    for(int i = 0;i<minSize;i++){
        if(lhs.contains(i) && !rhs.contains(i)){
            diff.add(i);
        }
    }
    
    return diff;
    
}


MultiSet complement(const MultiSet& orig) {
    
    MultiSet complemented(orig);
    
    for (int i = 0; i < orig.maxNum; i++) {
        if (orig.contains(i)) {
            complemented[i] = (1 << orig.bits) - 1 - orig[i];
        }
    }
    
    return complemented;
}



void MultiSet::writeToBinary(std::ofstream& ofs){
    
    if(!ofs.is_open()){
        return;
    }
    
    ofs.write((const char*) &maxNum,sizeof(maxNum));
    ofs.write((const char*) &bits,sizeof(bits));
    
    ofs.write((const char*) buckets,sizeof(uint8_t) * maxNum + 1);
    
    ofs.close();
}

void MultiSet::readFromBinary(std::ifstream& ifs){
    
    if(!ifs.is_open()){
        return;
    }
    
    unsigned size;
    ifs.read((char*) &size,sizeof(size));
    
    uint8_t bits;
    ifs.read((char*) &bits,sizeof(bits));

    delete[]this->buckets;
    
    this->buckets = new uint8_t[size];
    this->maxNum = size;
    
    ifs.read((char*) buckets,sizeof(uint8_t) * maxNum + 1);
    
    ifs.close();
    
}
