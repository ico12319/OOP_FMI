#include <stdio.h>
#include "ValueFiller.h"



static size_t getFileSize(std::ifstream& ifs){
    size_t currPos = ifs.tellg();
    ifs.seekg(0,std::ios::end);
    size_t fileSize = ifs.tellg();
    ifs.seekg(currPos);
    return fileSize;
}



ValueFiller::ValueFiller(const char* filePath){
    load(filePath);
}

ValueFiller::ValueFiller(const ValueFiller& other){
    copy(other);
}

ValueFiller::ValueFiller(ValueFiller&& other){
    move(std::move(other));
}

ValueFiller& ValueFiller::operator=(const ValueFiller& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}

ValueFiller& ValueFiller::operator=(ValueFiller&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

ValueFiller::~ValueFiller(){
    destroy();
}


void ValueFiller::destroy(){
    delete[]data;
    data = nullptr;
}

void ValueFiller::copy(const ValueFiller& other){
    this->data = new int[other.size];
    for(int  i = 0;i<other.size;i++){
        this->data[i] = other.data[i];
    }
    this->size = other.size;
    this->loaded = other.loaded;
}

void ValueFiller::load(const char* filePath){
    std::ifstream ifs(filePath,std::ios::binary);
    if(!ifs.is_open()){
        throw std::logic_error("Error");
    }
    size = getFileSize(ifs) / sizeof(int);
    data= new int[size];
    ifs.read((char*)data, size * sizeof(int));
    loaded = true;
}


void ValueFiller::move(ValueFiller&& other){
    this->data = other.data;
    other.data = nullptr;
    this->size = other.size;
    other.size = 0;
    this->loaded = other.loaded;
    other.loaded = false;
}

bool ValueFiller::good()const{
    return loaded;
}


void ValueFiller::print() const{
    for(int i = 0;i<size;i++)
        std::cout<<data[i]<<" ";
}


size_t ValueFiller::getSize() const{
    return size;
}

int ValueFiller::getElementOnIndex(size_t index) const{
    if(index > size)
        throw std::invalid_argument("Out of bounds!");
    
    return data[index];
}
