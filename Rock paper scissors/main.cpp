#include "GameFactory.h"

Type* gameFactory(){
    int gameType;
    std::cin >> gameType;
    
    switch(gameType){
        case 1:
            return new Rock();
        case 2:
            return new Scissor();
        case 3:
            return new Paper();
        default:
            return nullptr;
            break;
    }
}

Output determineWinnerBetweenTwo(Type* lhs,Type* rhs){
    return lhs->beats(rhs);
}


int main(int argc, const char * argv[]) {
    GameFactory game;
    size_t n;
    std::cin >> n;
    
    for(int i = 0;i<n;i++)
        game.addPlayer(gameFactory());
    
    Type* ptr1 = game.getPlayer(0);
    Type* ptr2 = game.getPlayer(1);
    Type* ptr3 = game.getPlayer(2);
    Type* ptr4 = game.getPlayer(3);
    
    game.addPlayer(ptr1);
    game.addPlayer(ptr2);
    game.addPlayer(ptr3);
    game.addPlayer(ptr4);
    
    
    //Type* ptr = new Rock();
    //Type* ptr6 = new Rock();
    //std::cout<<determineWinnerBetweenTwo(ptr, ptr6)<<std::endl;
    
    //Type* winner = game.determineWinner();
    
    
    //winner->print();
}
