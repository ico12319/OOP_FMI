#include <iostream>

class StringPool{
    
private:
    struct StringRecord{
        char* str = nullptr;
        unsigned refCount = 0;
    };
    
    StringRecord* records;
    size_t stringCount;
    size_t capacity;
    
    void resize(unsigned newCap);
    void removeRecord(unsigned index);
    int findRecord(const char* str) const;
    
    
public:
    StringPool();
    const char* getAllocatedString(const char* str);
    void releaseString(const char* str);
    
};
