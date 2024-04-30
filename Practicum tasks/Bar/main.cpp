#include <iostream>
#include "Bar.h"

int main(int argc, const char * argv[]) {
    Bar bar;
    
    Drink drink1("Coke",330);
    Drink drink2("Fanta",730);
    Drink drink3("Boza",130);
    
    AlcoholDrink aDrink1("Zagorka",550,5);
    AlcoholDrink aDrink2("Roze",900,45);
    
    bar.addDrink(drink1);
    bar.addDrink(drink2, 3);
    bar.addDrink(drink3);
    bar.addAlcoholDrink(aDrink2);
    bar.addAlcoholDrink(aDrink1, 2);
    
    
    bar.getDrink();
    bar.getDrink();
    bar.getDrink();
    
    std::cout<<bar.getDrinksSold()<<std::endl;
    
    bar.getAlcoholDrink();
    std::cout<<bar.getAlcoholDrinksSold()<<std::endl;
    
    std::cout<<bar.getTotalMlSold()<<std::endl;
    
    bar.printDrinks();
    
    
}
