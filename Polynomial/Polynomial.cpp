#include <stdio.h>
#include "Polynomial.h"


const int Polynomial::getPower() const{
    
    return this->power;
}



void copyArr(int* orig,const int* cont,int start,int size){
    for(int i = start;i<size;i++){
        orig[i] = cont[i];
    }
}

void Polynomial::copy(const Polynomial& other){
    
    this->power = other.power;
    this->polynom = new int[other.power + 1];
    for(int i = 0;i<other.power + 1;i++){
        this->polynom[i] = other.polynom[i];
    }
}


void Polynomial::destroy(){
    
    delete[] this->polynom;
    this->power = 0;
}

void Polynomial::setPolynom(int power, const int* polynom){
    
    if(polynom == nullptr || this->polynom == polynom){
        return;
    }
    delete[] this->polynom;
    
    this->power = power;
    this->polynom = new int[power + 1];
    for(int i = 0; i<power + 1;i++){
        this->polynom[i] = polynom[i];
    }
    
}

Polynomial::Polynomial(int power,const int* polynom){
    setPolynom(power, polynom);
}

Polynomial::Polynomial(const Polynomial& other){
    copy(other);
}

Polynomial& Polynomial::operator=(const Polynomial& other){
    
    if(this!=&other){
        destroy();
        copy(other);
    }
    
    return *this;
    
}

Polynomial::~Polynomial(){
    destroy();
}


Polynomial& Polynomial::operator+=(const Polynomial& other){
    
    if(this->power > other.power){
        
        for(int i = 0; i<other.power + 1;i++){
            this->polynom[i]+=other.polynom[i];
        }
        
    }
    else{
        int* newPolynom = new int[other.power + 1];
        
        copyArr(newPolynom, this->polynom, 0,this->power+1);
        
        for(int i = 0;i<this->power+1;i++){
            newPolynom[i]+=other.polynom[i];
        }
        
        copyArr(newPolynom, other.polynom, this->power + 1,other.power + 1);
        
        delete[] this->polynom;
        
        this->polynom = newPolynom;
        this->power = other.power;
    }
    
    return *this;
    
}

Polynomial& Polynomial::operator-=(const Polynomial& other){
    
    if(this->power > other.power){
        
        for(int i = 0;i<other.power;i++){
            this->polynom[i]-=other.polynom[i];
        }
    }
    else{
        int* newPolynom = new int[other.power + 1];
        
        copyArr(newPolynom, this->polynom, 0, this->power + 1);
        
        for(int i = 0; i<this->power + 1;i++){
            newPolynom[i] -= other.polynom[i];
        }
        
        copyArr(newPolynom, other.polynom, this->power + 1, other.power + 1);
        delete[] this->polynom;
        this->polynom = newPolynom;
        this->power = other.power;
    }
    
    return *this;
}


Polynomial& Polynomial::operator*=(const Polynomial& other){
    
    if(this->power > other.power){
        for(int i = 0;i<other.power + 1;i++){
            this->polynom[i] *= other.polynom[i];
        }
    }
    else{
        int* newPolynom = new int[other.power + 1];
        copyArr(newPolynom, this->polynom, 0, this->power + 1);
        
        for(int i = 0;i<this->power + 1;i++){
            newPolynom[i] *= other.polynom[i];
        }
        
        copyArr(newPolynom, other.polynom, this->power + 1, other.power + 1);
        delete[] this->polynom;
        this->polynom = newPolynom;
        this->power = other.power;
    }
    return *this;
}

const int& Polynomial::operator[](int index) const{
    return this->polynom[index];
}

int& Polynomial::operator[](int index){
    return this->polynom[index];
}

bool operator==(const Polynomial& lhs,const Polynomial& rhs){
    
    if(lhs.getPower()!=rhs.getPower()){
        return false;
    }
    
    for(int i= 0;i<lhs.getPower() + 1;i++){
        if(lhs[i] != rhs[i]){
            return false;
        }
    }
    return true;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs==rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    
    Polynomial toReturn(lhs);
    toReturn += rhs;
    
    return toReturn;
    
}

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs){
    
    Polynomial toReturn(lhs);
    toReturn -= rhs;
    
    return toReturn;
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs){
    
    Polynomial toReturn(lhs);
    
    toReturn *= rhs;
    
    return toReturn;
    
}

int Polynomial::operator()(int toApply) const{
    int res = 0;
    int curr = 1;
    for(int i = 0;i<power + 1;i++){
        res += polynom[i] * curr;
        curr *= toApply;
    }
    
    return res;
}

std::ostream& operator<<(std::ostream& os,const Polynomial& polyn){
    
    for(int i = 0;i<polyn.power + 1;i++){
        if(i == 0){
            os<<polyn.polynom[i];
        }
        else{
            os<<polyn.polynom[i]<<"x";
            if(i > 1){
                os<<"^"<<i;
            }
        }
        if(i!=polyn.power){
            os<<"+";
        }
    }
    
    return os;
}
