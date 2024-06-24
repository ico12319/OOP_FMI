#include "AlcoholDrink.h"


class FizzyDrink : public Drink{
    
    
public:
    FizzyDrink(const char* name,double price);
    virtual Drink* clone() const override;
    virtual DrinkType getType() const override;
    virtual void print() const override;
    
};
