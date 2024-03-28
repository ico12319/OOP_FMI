#include "Client.h"


int main(){
    
    Client client("Chica",WHISKEY);
    
    client.printFavDrinks();
    client.changeToLike(VODKA);
    client.printFavDrinks();
    
    
    std::cout<<client.likesDrink(VODKA)<<std::endl;
    std::cout<<client.likesDrink(FANTA)<<std::endl;
    client.changeToDislike(VODKA);
    
    client.printFavDrinks();
    
    
    
    
    
}
