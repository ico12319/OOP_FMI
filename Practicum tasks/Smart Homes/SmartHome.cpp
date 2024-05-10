#include <stdio.h>
#include "SmartHome.h"

void SmartHome::addDevice(Device* device){
    if(devicesCount >= MAX_SMART_DEVICES){
        std::cerr<<"The collection is already full!"<<std::endl;
        return;
    }
    devices[devicesCount] = device;
    devicesCount++;
}


void SmartHome::removeDevice(Device* device){
    
    int index = 0;
    
    for(int i =0;i<devicesCount;i++){
        if(devices[i] == device){
            index = i;
            delete devices[i];
            break;
        }
    }
    
    for(int i = index;i<devicesCount - 1;i++){
        devices[i] = devices[i+1];
    }
    devicesCount--;
}


void SmartHome::printDevices() const{
    for(int i = 0;i<devicesCount;i++){
        devices[i]->printDetails();
    }
}


void SmartHome::removeDeviceOnIndex(size_t index){
    if(index >= devicesCount){
        std::cerr<<"Out of bounds!"<<std::endl;
        return;
    }
    
    delete devices[index];
    for(size_t i = index;i<devicesCount - 1;i++){
        devices[i] = devices[i+1];
    }
    
    devicesCount--;
}
