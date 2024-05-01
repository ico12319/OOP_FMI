#include "DynamicSet.h"



class SetByString : private DynamicSet{
    
private:
    char* data;
    
    void copy(const SetByString& other);
    void destroy();
    void move(SetByString&& other);
    
    void extractNums();
    
public:
    SetByString() = default;
    SetByString(unsigned maxNum, const char* data);
    SetByString(const SetByString& other);
    SetByString(SetByString&& other);
    SetByString& operator=(const SetByString& other);
    SetByString& operator=(SetByString&& other);
    ~SetByString();
    
    
    void setAt(int index, char s);
    bool contains(unsigned num) const;
    void remove(unsigned num);
    void add(unsigned num);
    void print()const;
    
    
};
