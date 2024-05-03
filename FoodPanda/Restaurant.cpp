#include <stdio.h>
#include "Restaurant.h"
#include <iostream>



String Restaurant::getResName() const{
    return this->resName;
}

Restaurant::Restaurant(const String& name,const Product* products,size_t productsCount){
    setName(name);
    this->products = new Product[productsCount];
    for(int i = 0;i<productsCount;i++){
        this->products[i] = products[i];
    }
    this->productsCount = productsCount;
    
    
}

void Restaurant::setName(const String& name){
    if(name.length() >= 25){
        std::cout<<"The name is too long!"<<std::endl;
        return;
    }
    
    this->resName = name;
}

void Restaurant::copy(const Restaurant& other){
    this->resName = other.resName;
    this->productsCount = other.productsCount;
    this->products = new Product[other.productsCount];
    for(int i = 0;i<other.productsCount;i++){
        this->products[i] = other.products[i];
    }
}


void Restaurant::destroy(){
    delete[] this->products;
    this->products = nullptr;
    
}

Restaurant::~Restaurant(){
    destroy();
}

Restaurant::Restaurant(const Restaurant& other){
    copy(other);
}

void Restaurant::move(Restaurant&& other){
    this->products = other.products;
    other.products = nullptr;
    
    this->productsCount = other.productsCount;
    other.productsCount = 0;
    
    this->resName = other.resName;
    other.resName = " ";
}

Restaurant::Restaurant(Restaurant&& other){
    move(std::move(other));
}

Restaurant& Restaurant::operator=(const Restaurant& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
}

Restaurant& Restaurant::operator=(Restaurant&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


void Restaurant::addProduct(const Product& product){
    products[productsCount] = product;
    productsCount++;
}


void Restaurant::printRestaurant(const Order& order) const{
    int ind = 0;
    
    std::cout<<"Here is your order: ";
    for(int i = 0;i<productsCount;i++){
        if(products[i].getName() == order.getProductOffered(ind).getName()){
            std::cout<<products[i].getName()<<" ";
            ind++;
            if(ind >= order.getCountsOfProductsOffered()){
                break;
            }
        }
    }
    std::cout<<std::endl;
    
}

void Restaurant::Order::copyFrom(const Order& other){
    this->resNameFor = other.resNameFor;
    this->countOfProductsOffered  = other.countOfProductsOffered;
    this->productsOffered = new Product[other.countOfProductsOffered];
    for(int i = 0;i<other.countOfProductsOffered;i++){
        this->productsOffered[i] = other.productsOffered[i];
    }
}

void Restaurant::Order::free(){
    delete[]this->productsOffered;
    this->productsOffered = nullptr;
}

Restaurant::Order::Order(const String& name, const Product* productsOffered, size_t countsOfProd){
    this->resNameFor = name;
    this->countOfProductsOffered = countsOfProd;
    this->productsOffered = new Product[countOfProductsOffered];
    for(int i = 0;i<countsOfProd;i++){
        this->productsOffered[i] = productsOffered[i];
    }
    
}

Restaurant::Order::Order(const Order& other){
    copyFrom(other);
}

Restaurant::Order::Order(Order&& other){
    moveFrom(std::move(other));
}

Restaurant::Order::~Order(){
    free();
}

Restaurant::Order& Restaurant::Order::operator=(const Order& other){
    if(this!=&other){
        free();
        copyFrom(other);
    }
    
    return *this;
}

Restaurant::Order& Restaurant::Order::operator=(Order&& other){
    if(this!=&other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Restaurant::Order::moveFrom(Order&& other){
    this->productsOffered = other.productsOffered;
    other.productsOffered = nullptr;
    
    this->countOfProductsOffered = other.countOfProductsOffered;
    this->resNameFor = other.resNameFor;
    other.resNameFor = " ";
}


bool Restaurant::offersProduct(const Product& prod) const{
    for(int i = 0;i<productsCount;i++){
        if(products[i].getName() == prod.getName()){
            return true;
        }
    }
    return false;
}


Product Restaurant::Order::getProductOffered(int index) const{
    if(index >= getCountsOfProductsOffered()){
        throw std::invalid_argument("Out of bounds!");
    }
    return this->productsOffered[index];
}


size_t Restaurant::Order::getCountsOfProductsOffered() const{
    return this->countOfProductsOffered;
}

String Restaurant::Order::getRestaurantName() const{
    return this->resNameFor;
}


int Restaurant::receiveOrder(const Order& order){

    int ind = 0;
    int minutes = 0;
    for(int i = 0;i<order.getCountsOfProductsOffered();i++){
        if(!offersProduct(order.getProductOffered(ind))){
            throw std::invalid_argument("One or more of the products provided in the order is not currently available!");
        }
        else{
            minutes+=30;
            ind++;
        }
    }
    return minutes;
}


