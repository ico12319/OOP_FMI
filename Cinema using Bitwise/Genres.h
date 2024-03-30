#include <iostream>

enum Genres:uint8_t{
    
    ACTION = 1 << 0,
    COMEDY = 1 << 1,
    DRAMA = 1 << 2,
    FANTASY = 1 << 3,
    HORROR = 1 << 4,
    MYSTERY = 1 << 5,
    ROMANCE = 1 << 6,
    TOTAL_GENRES_COUNT = 1 << 7
};
