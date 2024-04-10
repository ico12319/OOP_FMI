#include "stdint.h"
#include "Genres.h"

class Movie{
    
private:
    char* name = nullptr;
    char* producer = nullptr;
    int length = 0;
    uint8_t genres = 0;
    
    void copy(const Movie& other);
    void destroy();
    
public:
    Movie() = default;
    Movie(const char* name,const char* producer,int length,uint8_t genres);
    Movie(const Movie& other);
    Movie& operator=(const Movie& other);
    ~Movie();
    
    const char* getName() const;
    const char* getProducerName() const;
    int getLen() const;
    
    
    void setName(const char* name);
    void setProducer(const char* producer);
    void setLen(int len);
    void setGenres(uint8_t genres);
    
    
    bool hasGenre(Genres genre) const;
    void addGenre(const Genres& genre);
    void removeGenre(const Genres& genre);
    void printMovieInfo() const;
    
};
