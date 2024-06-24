#include "Bar.h"

int main(int argc, const char * argv[]) {
    
    Bar bar;
    
    Drink* drink = new FizzyDrink("Orlate",23.50);
    Drink* drink2 = new AlcoholDrink("Uckaa",8.75);
    Drink* drink3 = new FizzyDrink("Kisenko",18.64);
    Drink* drink4 = new AlcoholDrink("Mish",43.54);
    
    
    bar.addDrink(drink);
    bar.addDrink(drink2);
    bar.addDrink(drink3);
    bar.addDrink(drink4);
    
}
