#include "SmartHome.h"

int main(int argc, const char * argv[]) {
    
    Device* ptr1 = new SmartLight("Evo","Minc",58);
    Device* ptr2 = new SmartSpeaker("Alexa","Amazon",99);
    Device* ptr3 = new SmartThermostat("Thermo","Stat",56,120);
    
    SmartHome devices;
    devices.addDevice(ptr1);
    devices.addDevice(ptr2);
    devices.addDevice(ptr3);

    devices.removeDeviceOnIndex(0);
    devices.removeDevice(ptr3);
   
    devices.printDevices();
    
    
}
