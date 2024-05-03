#include "Product.h"

class Restaurant{
    
private:
    String resName;
    Product* products = nullptr;
    size_t productsCount = 0;
    
    void copy(const Restaurant& other);
    void destroy();
    void move(Restaurant&& other);
    
public:
    
    class Order{
    private:
        String resNameFor;
        Product* productsOffered;
        size_t countOfProductsOffered;
        
        void copyFrom(const Order& other);
        void free();
        void moveFrom(Order&& other);
        
    public:
        Order(const String& name, const Product* productsOffered,size_t countsOfProductsOffered);
        Order(const Order& other);
        Order(Order&& other);
        ~Order();
        Order& operator=(const Order& other);
        Order& operator=(Order&& other);
        
        Product getProductOffered(int index) const;
        size_t getCountsOfProductsOffered() const;
        String getRestaurantName() const;
    };
    
    Restaurant() = default;
    Restaurant(const String& name, const Product* products,size_t productsCount);
    Restaurant(const Restaurant& other);
    Restaurant(Restaurant&& other);
    ~Restaurant();
    Restaurant& operator=(const Restaurant& other);
    Restaurant& operator=(Restaurant&& other);
    
    String getResName() const;
    void setName(const String& name);
    
    
    bool offersProduct(const Product& prod) const;
    
    void addProduct(const Product& product);
    int receiveOrder(const Order& order);
    
    void printRestaurant(const Order& order) const;
};
