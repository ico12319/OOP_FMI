#ifndef CLIENT_H
#define CLIENT_H

#include "Drinks.h"
#include "stdint.h"




const int MAX_NAME_LEN = 31;
 

class Client{
private:
    char name[MAX_NAME_LEN + 1] = "Unknown";
    uint8_t favDrinks = 0;

public:
    Client() = default;
    Client(const char* name,uint8_t favDrinks);
    
    
    const char* getName() const;
    
    
    void setName(const char* name);
    void setFavDrink(uint8_t favDrinks);
    
    bool likesDrink(Drink drink) const;
    void changeToLike(Drink drink);
    void changeToDislike(Drink drink);
    void printFavDrinks() const;
    
    int getLikedDrinks() const;
    
    
};

#endif
