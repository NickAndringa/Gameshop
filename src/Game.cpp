#include "include/Game.hpp"

float Game::calculateCurrentPrice()const{
    float currentPrice = originalPrice;
    int age = 2022 - releaseDate;
    for(int i = 0; i < age; i++){
        currentPrice *= 0.7;
    }
    return currentPrice;
}

Game::Game(std::string title, int releaseDate, float originalPrice):
    title(title),
    releaseDate(releaseDate),
    originalPrice(originalPrice)
{}

bool operator==(const Game& game1, const Game& game2){
    if(game1.getTitle() == game2.getTitle()){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& print,const Game& game){
    print << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " 
          << game.getOriginalPrice() << " now: " << game.calculateCurrentPrice() << '\n';
    return print;
}