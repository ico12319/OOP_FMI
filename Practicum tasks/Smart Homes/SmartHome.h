#include "SmartSpeaker.h"

class SmartHome{
    
private:
    static constexpr size_t MAX_SMART_DEVICES = 10;
    Device* devices[MAX_SMART_DEVICES];
    size_t devicesCount = 0;
    
public:
    SmartHome() = default;
    
    void addDevice(Device* device);
    void removeDevice(Device* device);
    void printDevices() const;
    void removeDeviceOnIndex(size_t index);
    void addDeviceOnIndex(size_t index);
    
};
