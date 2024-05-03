#include <stdio.h>
#include "FoodPanda.h"
#include <iostream>

FoodPanda::FoodPanda(const Restaurant* restaurants,size_t restaurantsCount){
    this->restaurantsCount = restaurantsCount;
    this->restaurants = new Restaurant[restaurantsCount];
    for(int i = 0;i<restaurantsCount;i++){
        this->restaurants[i] = restaurants[i];
    }
}


void FoodPanda::copy(const FoodPanda& other){
    this->restaurantsCount = other.restaurantsCount;
    this->restaurants = new Restaurant[other.restaurantsCount];
    for(int i = 0;i<restaurantsCount;i++){
        this->restaurants[i] = other.restaurants[i];
    }
}

FoodPanda::FoodPanda(const FoodPanda& other){
    copy(other);
}


void FoodPanda::proccesOrder(const Restaurant::Order& order){
    bool isFound = 0;
    
    for(int i = 0;i<restaurantsCount;i++){
        if(restaurants[i].getResName() == order.getRestaurantName()){
            try{
                int minutes = restaurants[i].receiveOrder(order);
                std::cout<<"You order was proccessed successfully by "<<restaurants[i].getResName()<<"!"<<std::endl;
                std::cout<<"Expected delivery time: " << minutes << "minites."<<std::endl;
                restaurants[i].printRestaurant(order);
                isFound = true;
                break;
            }
            catch(const std::invalid_argument& i){
                std::cout<<i.what()<<std::endl;
                return;
            }
        }
    }
    
    if(!isFound){
        std::cout<<"Currently there is not a restaurant that can handle you order. Try agan!"<<std::endl;
    }
}


void FoodPanda::destroy(){
    delete[]this->restaurants;
    this->restaurants = nullptr;
}

FoodPanda::~FoodPanda(){
    destroy();
}

void FoodPanda::move(FoodPanda&& other){
    this->restaurants = other.restaurants;
    other.restaurants = nullptr;
    
    this->restaurantsCount = other.restaurantsCount;
    other.restaurantsCount = 0;
    
}


FoodPanda::FoodPanda(FoodPanda&& other){
    move(std::move(other));
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

FoodPanda& FoodPanda::operator=(FoodPanda&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    
    return *this;
}


