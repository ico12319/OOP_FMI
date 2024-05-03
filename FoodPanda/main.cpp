#include "FoodPanda.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    Product prod("Pizza");
    Product prod12("Spaghetti");
    Product prd2("Nuggets");
    Product prd3("Burger");
    
    
    
    Product products[] = {prod,prd2,prd3,prod12};
    Product prd[] = {prod,prd2,prd3};
    
    Restaurant res("Haralam", products, 3);
    Restaurant res1("Ejuk", products, 4);
    Restaurant res2("Gic", products, 3);

    
    
    Restaurant::Order order("Haralam",prd,1);
    Restaurant::Order order2("Ejuk", products, 4);
    Restaurant::Order order3("New York", products, 2);
    
    
    
    
    
    
    Restaurant restaurants[] = {res,res1,res2};
    
    FoodPanda glovo(restaurants, 3);
    
    glovo.proccesOrder(order);
   
    
    
    
}
