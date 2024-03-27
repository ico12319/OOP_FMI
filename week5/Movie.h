#include "Genres.h"


const int GENRES_MAX_COUNT = 7;

class Movie{
private:
    char* name = nullptr;
    char* producer = nullptr;
    int duration = 0;
    Genres genres[GENRES_MAX_COUNT];
    int currGenres = 0;
public:
    Movie() = default;
    Movie(const char* name,const char* producer,int duration,const Genres* genre,int currGenres);

    const char* getName() const;
    const char* getProducer() const;
    int getDuration() const;
    Genres getGenre(int index) const;

    void setName(const char* name);
    void setProducer(const char* producer);
    void setDuration(int duration);
    void setGenres(const Genres* genre);
    void setCurrGenres(int currGenres);


    void addGenre(Genres genre);
    void removeGenre(Genres genre);
    void printMovieInfo() const;




};
