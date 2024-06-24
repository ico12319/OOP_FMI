#include <iostream>
#include "DrinkType.h"


const int MAX_NAME_LEN = 1024;

class Drink{
    
protected:
    char name[1024];
    double price;
    
public:
    Drink(const char* name,double price);
    virtual ~Drink() = default;
    virtual Drink* clone() const = 0;
    virtual DrinkType getType() const = 0;
    virtual void print() const = 0;
    const char* getName() const;
    
};
