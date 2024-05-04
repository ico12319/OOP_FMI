#include <stdio.h>
#include "Tyres.h"



Tyres::Tyres(unsigned iD,const char* manifName,const char* description,short width,short profile,short diameter) : CarPart(iD, manifName, description){
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}


void Tyres::setWidth(short width){
    if(width < 155 || width > 365){
        return;
    }
    
    this->width = width;
}

void Tyres::setProfile(short profile){
    if(profile < 30 || profile > 80){
        return;
    }
    
    this->prfile = profile;
}

void Tyres::setDiameter(short dimeter){
    if(dimeter < 13 || dimeter > 21){
        return;
    }
    
    this->dimeter = dimeter;
}


std::ostream& operator<<(std::ostream& os,const Tyres& tyre){
    const CarPart& part = tyre;
    return os << part << " - " << tyre.width<<"/"<<tyre.prfile<<"R"<<tyre.dimeter<<std::endl;
}



