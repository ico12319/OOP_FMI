#include <stdio.h>
#include "Bar.h"
#include <iostream>



static void message(){
    std::cout<<"The bar is full!"<<std::endl;
}


void Bar::addDrink(const Drink& drink){
    if(normalDrinksCount < MAX_DRINKS && normalDrinksCount + alcoholDrinksCount < MAX_DRINKS){
        drinks[normalDrinksCount] = drink;
        normalDrinksCount++;
    }
    else{
        message();
    }
}

void Bar::addDrink(const Drink& drink, int count){
    if(normalDrinksCount < MAX_DRINKS && normalDrinksCount + count + alcoholDrinksCount < MAX_DRINKS){
        int origCount = normalDrinksCount;
        for(int i = origCount;i<count + origCount;i++){
            drinks[normalDrinksCount] = drink;
            normalDrinksCount++;
        }
    }
    else{
        message();
    }
}

void Bar::addAlcoholDrink(const AlcoholDrink& alcohol){
    if(alcoholDrinksCount < MAX_DRINKS && alcoholDrinksCount + normalDrinksCount < MAX_DRINKS){
        alcoholDrinks[alcoholDrinksCount] = alcohol;
        alcoholDrinksCount++;
    }
    else{
        message();
    }
}


void Bar::addAlcoholDrink(const AlcoholDrink& alcohol,int count){
    if(alcoholDrinksCount < MAX_DRINKS && alcoholDrinksCount + normalDrinksCount + count < MAX_DRINKS){
        int origCount = alcoholDrinksCount;
        for(int i = origCount;i<count + origCount;i++){
            alcoholDrinks[alcoholDrinksCount] = alcohol;
            alcoholDrinksCount++;
        }
    }
    else{
        message();
    }
}


Drink Bar::getDrink(){
    int maxCount = 0;
    int index = 0;
    for(int i = 0;i<normalDrinksCount;i++){
        int currCount = 1;
        for(int j = i+1;j<normalDrinksCount;j++){
            if(std::strcmp(drinks[i].getName(),drinks[j].getName())==0){
                currCount++;
            }
        }
        if(currCount > maxCount){
            maxCount = currCount;
            index = i;
        }
    }
    Drink toReturn = drinks[index];
    for(int i = index;i<normalDrinksCount - 1;i++){
        drinks[i] = drinks[i+1];
    }
    normalDrinksCount--;
    drinksSold++;
    totalMlSold += toReturn.getQuantity();
    return toReturn;
}


AlcoholDrink Bar::getAlcoholDrink(){
    int maxCount = 0;
    int index = 0;
    for(int i = 0;i<alcoholDrinksCount;i++){
        int currCount = 1;
        for(int j = i+1;j<alcoholDrinksCount;j++){
            if(std::strcmp(alcoholDrinks[i].getName(),alcoholDrinks[j].getName())==0){
                currCount++;
            }
        }
        if(currCount > maxCount){
            maxCount = currCount;
            index = i;
        }
    }
    AlcoholDrink toReturn = alcoholDrinks[index];
    for(int i = index;i<alcoholDrinksCount - 1;i++){
        alcoholDrinks[i] = alcoholDrinks[i+1];
    }
    alcoholDrinksCount--;
    alcoholDrinksSold++;
    totalMlSold += toReturn.getQuantity();
    return toReturn;
}


int Bar::getTotalMlSold() const{
    return this->totalMlSold;
}

int Bar::getDrinksSold() const{
    return this->drinksSold;
}

int Bar::getAlcoholDrinksSold() const{
    return this->alcoholDrinksSold;
}


void Bar::printDrinks() const{
    
    for(int i = 0;i<normalDrinksCount;i++){
        std::cout<<drinks[i].getName()<<" ";
    }
    std::cout<<std::endl;
    
}

void Bar::printAlcoholDrinks() const{
    
    for(int i = 0;i<alcoholDrinksCount;i++){
        std::cout<<alcoholDrinks[i].getName()<<" ";
    }
    std::cout<<std::endl;
    
}

