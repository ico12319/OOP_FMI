#include <stdio.h>
#include "Product.h"


Product::Product(const String& name){
    this->name = name;
}

String Product::getName() const{
    return this->name;
}
