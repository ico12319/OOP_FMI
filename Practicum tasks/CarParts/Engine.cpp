#include <stdio.h>
#include "Engine.h"


Engine::Engine(unsigned iD,const char* manifName,const char* description,unsigned horsePower) : CarPart(iD, manifName, description){
    this->horsePower = horsePower;
    
}


std::ostream& operator<<(std::ostream& os,const Engine& engine){
    const CarPart& part = engine;
    return os << part << " - " << engine.horsePower<<" hp." <<std::endl;
}


unsigned Engine::getHorsePower() const{
    return this->horsePower;
}
