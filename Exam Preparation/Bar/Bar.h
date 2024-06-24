#include "FizzyDrink.h"
#include <fstream>


class Bar{
    
private:
    Drink** drinks;
    size_t count;
    size_t capacity;
    
    void move(Bar&& other);
    void copy(const Bar& other);
    void destroy();
    void resize(size_t newCap);
    
public:
    Bar();
    Bar(const Bar& other);
    Bar(Bar&& other);
    Bar& operator=(const Bar& other);
    Bar& operator=(Bar&& other);
    ~Bar();
    
    void printBar() const;
    DrinkType getType(size_t index) const;
    void removeDrink(size_t index);
    void addDrink(Drink* drink);
    bool containsDrink(Drink* drink) const;
    
};
