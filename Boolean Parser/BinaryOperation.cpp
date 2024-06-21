#include <stdio.h>
#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(const Expression* left,const Expression* right){
    this->left = left->clone();
    this->right = right->clone();
}

BinaryOperation::BinaryOperation(const BinaryOperation& other){
    copy(other);
}

BinaryOperation::BinaryOperation(BinaryOperation&& other){
    move(std::move(other));
}

BinaryOperation& BinaryOperation::operator=(const BinaryOperation& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

BinaryOperation& BinaryOperation::operator=(BinaryOperation&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


void BinaryOperation::destroy(){
    delete left;
    delete right;
}

void BinaryOperation::copy(const BinaryOperation& other){
    this->left = other.left->clone();
    this->right = other.right->clone();
}

void BinaryOperation::move(BinaryOperation&& other){
    this->left = other.left;
    this->right = other.right;
    other.left = other.right = nullptr;
}

BinaryOperation::~BinaryOperation(){
    destroy();
}
