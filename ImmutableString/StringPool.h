
class StringPool{
    
private:
    
    struct StringRecord{
        char* str = nullptr;
        size_t refCount = 0;
        
    };
    
    StringRecord* stringRecords;
    unsigned stringCount = 0;
    unsigned capacity = 0;
    
    void resize(size_t newCap);
    void removeString(size_t index);
    unsigned allocateNewString(const char* data);
    int findAllocatedString(const char* data);
    
    
public:
    StringPool();
    const char* getAllocatedString(const char* str);
    void releaseString(const char* str);
    
    
};
