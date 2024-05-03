#include "String.h"

class Product{
    
private:
    String name = "Undefined";
    
    
public:
    Product() = default;
    Product(const String& name);
    
    String getName() const;
    
};
