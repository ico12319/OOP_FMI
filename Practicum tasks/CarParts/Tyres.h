#include "CarPart.h"


class Tyres : public CarPart{
    
private:
    short width = 0;
    short prfile = 0;
    short dimeter = 0;
    
public:
    Tyres() = default;
    Tyres(unsigned iD, const char* manifName, const char* description,short width,short profile,short diameter);
    
    void setWidth(short width);
    void setProfile(short profile);
    void setDiameter(short diameter);
    
    
    friend std::ostream& operator<<(std::ostream& os,const Tyres& tyre);
    
};
