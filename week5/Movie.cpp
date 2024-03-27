
#include "Movie.h"
#include <cstring>
#include <iostream>

const char* Movie::getName() const{
    return this->name;
}

const char* Movie::getProducer() const{
    return this-> producer;
}

int Movie::getDuration() const{
    return this->duration;
}

Genres Movie::getGenre(int index) const{
    return this->genres[index];
}

void Movie::setName(const char* name){
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name,name);
}

void Movie::setProducer(const char* producer){
    this->producer = new char[std::strlen(producer) + 1];
    std::strcpy(this->producer,producer);
}

void Movie::setDuration(int duration){
    this->duration = duration;
}

void Movie::setGenres(const Genres* genres){
    for(size_t i = 0;i<GENRES_MAX_COUNT;i++){
        this->genres[i] = genres[i];
    }
}

void Movie::setCurrGenres(int currGenres){
    this->currGenres = currGenres;
}

Movie::Movie(const char* name,const char* producer,int duration,const Genres* genres,int currGenres){
    setName(name);
    setProducer(producer);
    setDuration(duration);
    setGenres(genres);
    setCurrGenres(currGenres);
}


void Movie::addGenre(Genres genre){
    if(currGenres < GENRES_MAX_COUNT){
        genres[currGenres] = genre;
        currGenres++;
    }
}

void Movie::removeGenre(Genres genre){
    
    for(int i = 0;i<currGenres;i++){
        if(genres[i] == genre){
            for(int j = i;j<currGenres-1;j++){
                genres[j] = genres[j+1];
            }
            currGenres--;
            break;
        }
    }
}

void Movie::printMovieInfo() const{
    
    std::cout<<"Movie: " <<name<<std::endl;
    std::cout<<"Producer: " <<producer<<std::endl;
    std::cout<<"Duration: " <<duration<<" " <<"munites"<<std::endl;
    std::cout<<"Genre: ";
    if(currGenres > 1){
        for(int i = 0;i<currGenres;i++){
            switch(genres[i]){
                case Genres::ACTION:
                    std::cout<<"Action"<<"\\";
                    break;
                case Genres::HORROR:
                    std::cout<<"Horror"<<"\\";
                    break;
                case Genres::COMEDY:
                    std::cout<<"Comedy"<<"\\";
                    break;
                case Genres::DRAMA:
                    std::cout<<"Drama"<<"\\";
                    break;
                case Genres::FANTASY:
                    std::cout<<"Fantasy"<<"\\";
                    break;
                case Genres::ROMANCE:
                    std::cout<<"Romance"<<"\\";
                    break;
                case Genres::MYSTERY:
                    std::cout<<"Mystery"<<"\\";
                    break;
            }
        }
        std::cout<<std::endl;
    }
    else{
        switch(genres[0]){
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
        }
    }
}
