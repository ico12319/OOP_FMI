#include <iostream>

class SortedStringPool{
    
private:
    
    struct LittleString{
    private:
        char str[64] = " ";
        unsigned refCount = 0;
        
        void setStr(const char* str){
            std::strcpy(this->str,str);
        }
        
    public:
       explicit LittleString(const char* str){
            setStr(str);
        }
        
       const char* getStr() const{
            return this->str;
        }
        
        unsigned getRefCount() const{
            return this->refCount;
        }
        
        void incrementRefCount(){
            refCount++;
        }
        
        void decrementRefCount(){
            refCount--;
        }
        
        
    };
    
    LittleString** lStrings;
    size_t capacity;
    size_t stringCount;
    
    void copy(const SortedStringPool& other);
    void destroy();
    void move(SortedStringPool&& other);
    void resize(unsigned newCap);
    
public:
    SortedStringPool();
    SortedStringPool(const SortedStringPool& other);
    SortedStringPool(SortedStringPool&& other);
    SortedStringPool& operator=(const SortedStringPool& other);
    SortedStringPool& operator=(SortedStringPool&& other);
    ~SortedStringPool();
    
    void addString(const char* str);
    void removeString(size_t index);
    bool contains(const char* str) const;
    
    void printCollection() const;
    
};
