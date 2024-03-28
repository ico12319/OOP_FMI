#include "Client.h"
#include <cstring>



const char* Client::getName() const{
    return this->name;
}

void printDrink(Drink drink){
    switch (drink)
        {
        case WHISKEY:
            std::cout << "whiskey";
            break;
        case VODKA:
            std::cout << "vodka";
            break;
        case COLA:
            std::cout << "cola";
            break;
        case FANTA:
            std::cout << "fanta";
            break;
        case WATER:
            std::cout << "water";
            break;
        case WINE:
            std::cout << "wine";
            break;
        case RHUM:
            std::cout << "rhum";
            break;
        case JUICE:
            std::cout << "juice";
            break;
        default:

            break;
        }
    }


void Client::setName(const char* name){
    std::strcpy(this->name, name);
}

void Client::setFavDrink(uint8_t favDrinks){
    this->favDrinks = favDrinks;
}

Client::Client(const char* name,uint8_t favDrinks){
    setName(name);
    setFavDrink(favDrinks);
}


bool Client::likesDrink(Drink drink) const{
    return (favDrinks & drink) != 0;
}

void Client::changeToDislike(Drink drink){
    
    favDrinks &= ~drink;
}

void Client::changeToLike(Drink drink){
    favDrinks |= drink;
}

Drink getStart(){
    return WHISKEY;
}


Drink getEnd(){
    return END;
}


Drink iterateDrink(Drink drink){
    return Drink(drink << 1);
}

int Client::getLikedDrinks() const{
    int count = 0;
    for(Drink i = getStart();i!=getEnd();i = iterateDrink(i)){
        if(likesDrink(i)){
            count++;
        }
    }
    return count;
}

void Client::printFavDrinks() const{
    
    int likedDrinksCount = getLikedDrinks();
    std::cout <<"Name: " << name<<" " <<"likes -> ";
    
    for(Drink i = getStart(); i!=getEnd(); i = iterateDrink(i)){
        if(likesDrink(i)){
            printDrink(i);
            if(likedDrinksCount > 1){
                std::cout<<", ";
                likedDrinksCount--;
            }
        }
        
    }
    std::cout<<std::endl;
 }
