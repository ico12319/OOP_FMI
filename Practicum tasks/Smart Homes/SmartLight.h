#include "Device.h"

class SmartLight : public Device{
    
private:
    short brightnessLevel;
    
public:
    SmartLight(const char* name,const char* manifacturer,short brightnessLevel);
    
    void turnOn() const override;
    void turnOff() const override;
    
    void printDetails() const override;
    
};
