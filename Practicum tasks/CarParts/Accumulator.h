#include "Engine.h"



class Accumulator : public CarPart{
    
private:
    unsigned capacity;
    char* batteryId;
    
    void copy(const Accumulator& other);
    void destroy();
    void move(Accumulator&& other);
    
    
public:
    Accumulator() = default;
    Accumulator(unsigned iD,const char* manifName,const char* descritpion,unsigned capacity,const char* batteryId);
    Accumulator(const Accumulator& other);
    Accumulator(Accumulator&& other);
    Accumulator& operator=(const Accumulator& other);
    Accumulator& operator=(Accumulator&& other);
    ~Accumulator();
    
    
    friend std::ostream& operator<<(std::ostream& os,const Accumulator& accum);
    
};
