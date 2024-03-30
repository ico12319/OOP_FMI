
#include "MovieSchedule.h"


int main(){
    
    
    Movie movie1("Kung-Fu Panda","Ivan Mishev",120,12);
    Movie movie2("Kisera","Hadzhi Misho",75,4);
    Movie movie3("Kishada","Venil",94,45);
    
    Movie movies[] = {movie1,movie2};
    
    MovieSchedule moviesList(movies,2);
    
    moviesList.addMovieToList(movie3);
    
    moviesList.printMovieInfo();
    
    std::cout<<std::endl;
    
    moviesList.moviesTotalLen();
}
