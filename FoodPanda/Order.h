#include "Product.h"


class Order{

private:
    String resNameFor;
    size_t countOfProducts = 0;
    Product* productsOffered = nullptr;
    
    void copy(const Order& other);
    
};
