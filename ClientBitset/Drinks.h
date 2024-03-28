#ifndef DRINKS_H
#define DRINKS_H
#include <iostream>


enum Drink{
    
    WHISKEY = 1 << 0,
    VODKA = 1 << 1,
    COLA = 1 << 2,
    FANTA = 1 << 3,
    WATER = 1 << 4,
    WINE = 1 << 5,
    RHUM = 1 << 6,
    JUICE = 1 << 7,
    END = 1 << 8
    
};

#endif
