#include <stdio.h>
#include "ModifiableIntegerFunction.h"
#include <iostream>


ModifiableIntegerFunction::ModifiableIntegerFunction(int16_t (*base) (int16_t)){
    this->func = base;
    for(int i = 0;i<SIZE;i++){
        modificatedResults[i] = func(i);
    }
}

void ModifiableIntegerFunction::setResult(int16_t value, int16_t result){
    modificatedResults[value] = result;
}

void ModifiableIntegerFunction::excludePoint(int16_t value){
    isPointExcluded[value] = 1;
}



int16_t ModifiableIntegerFunction::operator()(int16_t value){
    
    if(isPointExcluded[value]){
        std::cout<<"The value has been excluded!"<<std::endl;
        return 0;
    }
    return modificatedResults[value];
}


ModifiableIntegerFunction& ModifiableIntegerFunction::operator+=(const ModifiableIntegerFunction& other){
    
    
    for(int i = 0;i<SIZE;i++){
       
        if (!other.isPointExcluded[i]) {
            modificatedResults[i] += other.modificatedResults[i];
        }
    }
    
    return *this;
}


ModifiableIntegerFunction& ModifiableIntegerFunction::operator-=(const ModifiableIntegerFunction& other){
    
    for(int i = 0;i<SIZE;i++){
        if(!other.isPointExcluded[i]){
            modificatedResults[i] -= other.modificatedResults[i];
        }
    }
    
    return *this;
}



ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    
    ModifiableIntegerFunction result;
    
    for(int i = 0;i<ModifiableIntegerFunction::SIZE;i++){
        
        if(lhs.isPointExcluded[i]){
            result.modificatedResults[i] = rhs.modificatedResults[i];
        }
        else if(rhs.isPointExcluded[i]){
            result.modificatedResults[i] = lhs.modificatedResults[i];
        }
        else if(rhs.isPointExcluded[i] && lhs.isPointExcluded[i]){
            result.modificatedResults[i] = 0;
        }
        else{
            result.modificatedResults[i] = lhs.modificatedResults[i] + rhs.modificatedResults[i];
        }
    }
    
    return result;
}

ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    
    ModifiableIntegerFunction result;
    
    for(int i = 0;i<ModifiableIntegerFunction::SIZE;i++){
        
        if(lhs.isPointExcluded[i]){
            result.modificatedResults[i] = rhs.modificatedResults[i];
        }
        else if(rhs.isPointExcluded[i]){
            result.modificatedResults[i] = lhs.modificatedResults[i];
        }
        else if(!rhs.isPointExcluded[i] && lhs.isPointExcluded[i]){
            result.modificatedResults[i] = 0;
        }
        else{
            result.modificatedResults[i] = lhs.modificatedResults[i] - rhs.modificatedResults[i];
        }
    }
    
    return result;
    
}




ModifiableIntegerFunction operator^(ModifiableIntegerFunction& func, int times) {
    
    
    ModifiableIntegerFunction result = func;
    
    for (int i = 1; i < times; i++) {
        result.modificatedResults[i] = result.modificatedResults[i] *  func.modificatedResults[i];
    }
    
    return result;
}



bool ModifiableIntegerFunction::isSurjective() const{
    
    for(int i = 0;i<SIZE;i++){
        if(!isPointExcluded[i] && modificatedResults[i] == 0){
            return false;
        }
    }
    return true;
}

bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    for (size_t i = 2; i < ModifiableIntegerFunction::SIZE; i++){
        
        if (lhs.modificatedResults[i] < 0 || rhs.modificatedResults[i] < 0){
            break;
        }
        if (lhs.modificatedResults[i] <= rhs.modificatedResults[i]){
            return false;
        }
       
    }
    return true;
}



bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    for (size_t i = 2; i < ModifiableIntegerFunction::SIZE; i++){
        if (lhs.modificatedResults[i] < 0 || rhs.modificatedResults[i] < 0){
            break;
        }
        if (lhs.modificatedResults[i] >= rhs.modificatedResults[i]){
            return false;
        }

    }
    return true;
}


bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    for (size_t i = 2; i < ModifiableIntegerFunction::SIZE; i++){
        
        if (lhs.modificatedResults[i] < 0 || rhs.modificatedResults[i] < 0){
            break;
        }
        if (lhs.modificatedResults[i] < rhs.modificatedResults[i]){
            return false;
        }

    }
    return true;
}

bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    for (size_t i = 2; i < ModifiableIntegerFunction::SIZE; i++){
        
        if (lhs.modificatedResults[i] < 0 || rhs.modificatedResults[i] < 0){
            break;
        }
        if (lhs.modificatedResults[i] > rhs.modificatedResults[i]){
            return false;
        }

    }
    return true;
}


bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    for (size_t i = 0; i < ModifiableIntegerFunction::SIZE; i++){
        
        if (lhs.modificatedResults[i] != rhs.modificatedResults[i]){
            
            return false;
        }
    }
    return true;

}
bool operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs){
    
    return !(lhs == rhs);
}
