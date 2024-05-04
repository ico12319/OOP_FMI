#include "Tyres.h"

class Engine : public CarPart{
    
private:
    unsigned horsePower;
    
public:
    Engine() = default;
    Engine(unsigned iD,const char* manifName,const char* description,unsigned horsePower);
    
    unsigned getHorsePower() const;
    
    friend std::ostream& operator<<(std::ostream& os,const Engine& engine);
};
