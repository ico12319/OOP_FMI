#include <iostream>
#include <fstream>

class ValueFiller{

protected:
    int* data = nullptr;
    size_t size = 0;
    bool loaded = false;

    void load(const char* filePath);
    void copy(const ValueFiller& other);
    void destroy();
    void move(ValueFiller&& other);
    
public:
    ValueFiller() = default;
    ValueFiller(const char* filePath);
    bool good() const;
    ValueFiller(const ValueFiller& other);
    ValueFiller(ValueFiller&& other);
    ValueFiller& operator=(const ValueFiller& other);
    ValueFiller& operator=(ValueFiller&& other);
    ~ValueFiller();
    void print() const;
    size_t getSize() const;
    int getElementOnIndex(size_t index) const;
};
