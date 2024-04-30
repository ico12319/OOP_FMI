


class Drink{
    
private:
    char* name = nullptr;
    size_t quantity = 200;
    
    
    void copy(const Drink& other);
    void destroy();
    void move(Drink&& other);

public:
    Drink() = default;
    Drink(const char* name, size_t quantity);
    Drink(const Drink& other);
    Drink(Drink&& other);
    Drink& operator=(const Drink& other);
    Drink& operator=(Drink&& other);
    ~Drink();
    
    
    const char* getName() const;
    size_t getQuantity() const;
    void setName(const char* name);
    void setQuantity(size_t quantity);
    void printDrink() const;
    
    
    
};
