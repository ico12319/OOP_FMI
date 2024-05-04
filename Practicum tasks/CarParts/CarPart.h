#include <iostream>
#include <fstream>


class CarPart{
    
private:
    unsigned iD = 0;
    char* manifName = nullptr;
    char* description = nullptr;
    
    void copy(const CarPart& other);
    void destroy();
    void move(CarPart&& other);
    
public:
    CarPart() = default;
    CarPart(unsigned iD, const char* manifName, const char* description);
    CarPart(const CarPart& other);
    CarPart(CarPart&& other);
    CarPart& operator=(const CarPart& other);
    CarPart& operator=(CarPart&& other);
    ~CarPart();
    
    const char* getManifName() const;
    unsigned getId() const;
    const char* getDescription() const;
    
    friend std::ostream& operator<<(std::ostream& os,const CarPart& obj);
    
    
    
};
