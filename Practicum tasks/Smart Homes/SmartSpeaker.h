#include "SmartThermostat.h"

class SmartSpeaker : public Device{

private:
    size_t volume;
    
public:
    SmartSpeaker(const char* name,const char* manifacturer,size_t volume);
    
    void turnOn() const override;
    void turnOff() const override;
    void printDetails() const override;
    
    
    
};

