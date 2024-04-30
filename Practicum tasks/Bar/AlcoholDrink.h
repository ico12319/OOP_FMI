#include "Drink.h"


class AlcoholDrink : public Drink{
    
private:
    size_t percentAlcohol = 5;
    

public:
    AlcoholDrink() = default;
    AlcoholDrink(const char* name,size_t quantity,size_t percentAlcohol);
    
    
    void setPercentAlcohol(size_t percentAlcohol);
    
    
};
