#include "AlcoholDrink.h"


class Bar{

private:
    static const int MAX_DRINKS = 100;
    Drink drinks[MAX_DRINKS];
    AlcoholDrink alcoholDrinks[MAX_DRINKS];
    int normalDrinksCount = 0;
    int alcoholDrinksCount = 0;
    int totalMlSold = 0;
    
    int alcoholDrinksSold = 0;
    int drinksSold = 0;
public:
    Bar() = default;
    
    void addDrink(const Drink& drink);
    void addAlcoholDrink(const AlcoholDrink& alcohol);
    void addDrink(const Drink& drink,int count);
    void addAlcoholDrink(const AlcoholDrink& alcohol,int coubt);
    Drink getDrink();
    AlcoholDrink getAlcoholDrink();
    
    
    int getTotalMlSold() const;
    int getAlcoholDrinksSold() const;
    int getDrinksSold() const;
    
    void printDrinks() const;
    void printAlcoholDrinks() const;
    
    

    
};
