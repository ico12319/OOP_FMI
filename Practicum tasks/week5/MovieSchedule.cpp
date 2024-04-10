#include "MovieSchedule.hpp"
#include "iostream"

Movie MovieSchedule::getMovie(int index) const{
    return movies[index];
}

void MovieSchedule::setMovies(const Movie* movies,int currMovies){
    for(int i = 0;i<currMovies;i++){
        this->movies[i] = movies[i];
    }
    
}

void MovieSchedule::setCurrMovies(int currMovies){
    this->currMovies = currMovies;
}

MovieSchedule::MovieSchedule(const Movie* movies,int currMovies){
    setMovies(movies, currMovies);
    setCurrMovies(currMovies);
}

void MovieSchedule::addMovie(const Movie& movie){
    if(currMovies<MOVIES_COUNT){
        movies[currMovies] = movie;
        currMovies++;
    }
}

int MovieSchedule::totalDurationOfAllMovies(){
    
    int total = 0;
    for(int i = 0;i<currMovies;i++){
        total+=movies[i].getDuration();
    }
    return total;
    
}

void MovieSchedule::printMovieSartInfo(){
    
    for(int i = 0;i<currMovies;i++){
        std::cout<<movies[i].getName()<<"-"<<currHour<<":"<<currMinute<<std::endl;
        int totalMunutes = currHour*60 + currMinute+movies[i].getDuration();
        currHour = totalMunutes/60;
        currMinute = totalMunutes % 60;
    }
}
