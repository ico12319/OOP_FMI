#include <iostream>

class Device{
    
protected:
    char* name;
    char* manifacturer;
    
    void copy(const Device& other);
    void destroy();
    void move(Device&& other);
    
public:
    Device(const char* name,const char* manifacturer);
    Device(const Device& other);
    Device(Device&& other);
    virtual ~Device();
    Device& operator=(const Device& other);
    Device& operator=(Device&& other);
    
    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;
    virtual void printDetails() const;
    
};
