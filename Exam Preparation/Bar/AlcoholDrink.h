#include "Drink.h"


class AlcoholDrink : public Drink{
    
    
public:
    AlcoholDrink(const char* name,double price);
    virtual Drink* clone() const override;
    virtual DrinkType getType() const override;
    virtual void print() const override;
    
};
