#include <stdio.h>
#include "UnaryOperation.h"


UnaryOperation::UnaryOperation(const Expression* expr){
    this->expr = expr->clone();
}

UnaryOperation::UnaryOperation(const UnaryOperation& other){
    copy(other);
}

UnaryOperation::UnaryOperation(UnaryOperation&& other){
    move(std::move(other));
}

UnaryOperation& UnaryOperation::operator=(const UnaryOperation& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

UnaryOperation& UnaryOperation::operator=(UnaryOperation&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

UnaryOperation::~UnaryOperation(){
    destroy();
}


void UnaryOperation::move(UnaryOperation&& other){
    this->expr = other.expr;
    other.expr = nullptr;
}

void UnaryOperation::copy(const UnaryOperation& other){
    this->expr = other.expr->clone();
}

void UnaryOperation::destroy(){
    delete expr;
}
