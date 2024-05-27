#include <stdio.h>
#include "GameFactory.h"


GameFactory::GameFactory(){
    this->capacity = 8;
    this->data = new Type*[this->capacity];
    this->size = 0;
}


GameFactory::GameFactory(const GameFactory& other){
    copy(other);
}

GameFactory::GameFactory(GameFactory&& other) noexcept{
    move(std::move(other));
}


GameFactory& GameFactory::operator=(const GameFactory& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

GameFactory& GameFactory::operator=(GameFactory&& other) noexcept{
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}


void GameFactory::destroy(){
    for(int i = 0;i<size;i++){
        delete data[i];
    }
    delete[]data;
}

void GameFactory::copy(const GameFactory& other){
    this->capacity = other.capacity;
    this->data = new Type*[other.capacity];
    for(int i = 0;i<other.capacity;i++){
        this->data[i] = other.data[i] -> clone();
    }
    this->size = other.size;
}

void GameFactory::move(GameFactory&& other){
    this->data = other.data;
    other.data = nullptr;
    
    this->size = other.size;
    this->capacity = other.capacity;
    other.capacity = other.size = 0;
}
void GameFactory::resize(size_t newCap){
    Type** tempArr = new Type*[newCap];
    for(int i = 0;i<size;i++){
        tempArr[i] = data[i];
    }
    delete[]data;
    data = tempArr;
    capacity = newCap;
}

GameFactory::~GameFactory(){
    destroy();
}

void GameFactory::addPlayer(Type* type){
    if(type == nullptr)
        throw std::invalid_argument("Trying to access nullptr");
    
    if(size == capacity)
        resize(capacity * 2);
    data[size] = type;
    size++;
}

void GameFactory::addPlayer(const Type& type){
    
    Type* cloned = type.clone();
    addPlayer(cloned);
}

Output GameFactory::determineWinnerBetweenTwo(Type* lhs,Type* rhs){
    return lhs->beats(rhs);
}

Type* GameFactory::getPlayer(size_t index) const{
    return data[index];
}

void GameFactory::remove(size_t index){
    for(size_t i = index;i<size - 1;i++){
        data[i] = data[i+1];
    }
    size--;
}


Type* GameFactory::determineWinner() {
    int index1 = 0;
    int index2 = 1;
    while(size > 1){
        Output output = determineWinnerBetweenTwo(data[index1], data[index2]);
        if (output == Output::DRAW || output == Output::LOSS) {
                    remove(index2); // Remove the loser
                } else if (output == Output::WIN) {
                    remove(index1); // Remove the loser
                    index2--; // Adjust index2 to account for removal
                }
                index1 = 0; // Reset index1 to 0 after each iteration
                index2 = 1; // Reset index2 to 1 after each iteration
            }
            return data[0];
}
