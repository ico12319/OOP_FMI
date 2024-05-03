#include "Restaurant.h"

class FoodPanda{
    
private:
    Restaurant* restaurants = nullptr;
    size_t restaurantsCount = 0;
    
    void copy(const FoodPanda& other);
    void destroy();
    void move(FoodPanda&& other);
    
public:
    FoodPanda(const Restaurant* restaurants,size_t restaurantsCount);
    FoodPanda(const FoodPanda& other);
    FoodPanda(FoodPanda&& other);
    ~FoodPanda();
    FoodPanda& operator=(const FoodPanda& other);
    FoodPanda& operator=(FoodPanda&& other);
    
    
    void proccesOrder(const Restaurant::Order& order);
    
};
