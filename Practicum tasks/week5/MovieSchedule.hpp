#include "Movie.h"


const int MOVIES_COUNT = 10;

class MovieSchedule{
    
private:
    Movie movies[MOVIES_COUNT];
    int currMovies = 0;
    int currHour = 0;
    int currMinute = 0;
    
    
public:
    MovieSchedule() = default;
    
    MovieSchedule(const Movie* movies,int currMovies);
    
    Movie getMovie(int index) const;
    
    void setMovies(const Movie* movies,int currMovies);
    void setCurrMovies(int currMovies);
    
    void addMovie(const Movie& movie);
    
    void printMovieSartInfo();
    
    int totalDurationOfAllMovies();
    
    
    
};
