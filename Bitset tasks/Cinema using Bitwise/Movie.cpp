#include <stdio.h>
#include "Movie.h"
#include <cstring>
#include <stdint.h>


void printGenres(const Genres& genre){
    
            switch(genre){
                    case Genres::ACTION:
                        std::cout<<"Action";
                        break;
                    case Genres::HORROR:
                        std::cout<<"Horror";
                        break;
                    case Genres::COMEDY:
                        std::cout<<"Comedy";
                        break;
                    case Genres::DRAMA:
                        std::cout<<"Drama";
                        break;
                    case Genres::FANTASY:
                        std::cout<<"Fantasy";
                        break;
                    case Genres::ROMANCE:
                        std::cout<<"Romance";
                        break;
                    case Genres::MYSTERY:
                        std::cout<<"Mystery";
                        break;
                default:
                    break;
            }
}


const char* Movie::getName() const{
    return this->name;
}

const char* Movie::getProducerName() const{
    return this->producer;
}

int Movie::getLen() const{
    return this->length;
}

void Movie::setName(const char* name){
    if(name==nullptr || this->name == name){
        return;
    }
    
    delete[] this->name;
    
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

void Movie::setProducer(const char* producer){
    
    if(producer == nullptr || this->producer == producer){
        return;
    }
    delete[] this-> producer;
    
    this->producer = new char[std::strlen(producer) + 1];
    std::strcpy(this->producer, producer);
}

void Movie::setLen(int len){
    if(len < 0){
        return;
    }
    this->length = len;
}

void Movie::setGenres(uint8_t genres){
    this->genres = genres;
    
}

void Movie::copy(const Movie& other){
    
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
    
    this->producer = new char[std::strlen(other.name) + 1];
    std::strcpy(this->producer, producer);
    
    this->length = other.length;
    
    this->genres = other.genres;
    
}

void Movie::destroy(){
    delete[]name;
    delete[]producer;
    
    name = nullptr;
    producer = nullptr;
    this->length = 0;
    this->genres = 0;
}

Movie& Movie::operator=(const Movie& other){
    if(this != &other){
        destroy();
        copy(other);
    }
    
    return *this;
}

Movie::Movie(const Movie& other){
    copy(other);
}

Movie::~Movie(){
    destroy();
}

Movie::Movie(const char* name,const char* producer,int len,uint8_t genres){
    setName(name);
    setProducer(producer);
    setLen(len);
    setGenres(genres);
}


void Movie::addGenre(const Genres& genre){
    
     genres |= genre;
    
}

void Movie::removeGenre(const Genres& genre){
    
    genres ^= genre;
}


Genres startGenre(){
    return ACTION;
}

Genres endGenre(){
    return TOTAL_GENRES_COUNT;
}

Genres iterateGenres(Genres genre){
    return Genres(genre<<1);
}


bool Movie::hasGenre(Genres genre) const{
    return ((genres & genre) !=0);
}

void Movie::printMovieInfo() const{
    
    std::cout<<"Name: " << name<<std::endl;
    std::cout<<"Producer: " <<producer<<std::endl;
    std::cout<<"Length: " <<length<<std::endl;
    std::cout<<"Genres: ";
    for(Genres i = startGenre();i!=endGenre();i = iterateGenres(i)){
        if(hasGenre(i)){
            printGenres(i);
            std::cout<<", ";
        }
    }
    
}
