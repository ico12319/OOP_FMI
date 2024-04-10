#include <stdio.h>
#include "MovieSchedule.h"
#include <iostream>

void MovieSchedule::setMovies(const Movie* movies, unsigned currMovies){
    
    for(int i = 0;i<currMovies;i++){
        this->movies[i] = movies[i];
    }
    this->currMovies = currMovies;
}


MovieSchedule::MovieSchedule(const Movie* movies,unsigned currMovies){
    setMovies(movies, currMovies);
}

void MovieSchedule::addMovieToList(const Movie& movie){
    
    if(currMovies < MAX_MOVIES){
        movies[currMovies] = movie;
        currMovies++;
    }
    else{
        std::cerr<<"Not enough space in the list!"<<std::endl;
    }
}

void MovieSchedule::printMovieInfo() const{
    int startHour = 0;
    int startMinutes = 0;
    
    std::cout<<movies[0].getName()<<" " << "-> "<<startHour << ":" <<startMinutes<<std::endl;
    for(int i = 1;i<currMovies;i++){
        int totalMinutes = movies[i].getLen();
        startHour+=(totalMinutes/60);
        startMinutes+=(totalMinutes % 60);
        std::cout<<movies[i].getName()<<" " << "-> "<<startHour << ":" <<startMinutes<<std::endl;
        startHour = 0;
        startMinutes = 0;
    }
    
}

void MovieSchedule::moviesTotalLen(){
    
    int total = 0;
    for(int i = 0;i<currMovies;i++){
        total+=movies[i].getLen();
    }
    
    int hours = total / 60;
    int minutes = total % 60;
    
    std::cout<<"The total play-time of all movies in the list is " << hours << " " << "hours" <<" " <<"and " << minutes <<" " <<"minutes"<<"." <<std::endl;
    
}
