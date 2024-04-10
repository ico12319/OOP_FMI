#include <iostream>
#include "MovieSchedule.hpp"

int main(){
    
    Genres genre1[] = {HORROR,ACTION,ROMANCE};
    Genres genre2[] = {FANTASY};
    Genres genre3[] = {HORROR,ACTION};
    Genres genre4[] = {ROMANCE,COMEDY};
    
    Movie movie1("Teneva's END","Ivan Mihov",154,genre1,3);
    Movie movie2("Gerundii","Salam Ivanov",67,genre2,1);
    Movie movie3("Kolbasev Petuk","Suimak",123,genre3,2);
    Movie movie4("Eva - Marty","Muko",54,genre4,2);
    
    Movie movies[] = {movie1,movie2,movie3};
    
    MovieSchedule movieList(movies,3);
    
    movieList.addMovie(movie4);
    movieList.printMovieSartInfo();
    std::cout<<"The total duration of all movies in the list is: "<<movieList.totalDurationOfAllMovies()<<" " <<"minutes."<<std::endl;;
    
    
}
