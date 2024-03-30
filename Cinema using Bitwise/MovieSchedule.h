#include <iostream>
#include "Movie.h"

const int MAX_MOVIES = 10;


class MovieSchedule{
    
private:
    Movie movies[MAX_MOVIES];
    unsigned currMovies = 0;
    
public:
    MovieSchedule() = default;
    MovieSchedule(const Movie* movies,unsigned currMovies);
    
    void setMovies(const Movie* movies,unsigned currMovies);
    void addMovieToList(const Movie& movie);
    void printMovieInfo() const;
    
    void moviesTotalLen();
};
