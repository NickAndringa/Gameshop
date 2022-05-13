#include"include/Person.hpp"

bool Person::buy(Game game){
    if(budget > game.calculateCurrentPrice()){
        for(Game ownedGame : games){
            if(ownedGame == game){
                return false;
            }
        }
        budget -=game.calculateCurrentPrice();
        addGame(game);
        return true;
    }
    return false;
}

bool Person::sell(Game game, Person& buyer){
     for(Game ownedGame : games){
        if(ownedGame == game){
            bool hasBought = buyer.buy(game);
            if(hasBought){
                budget += game.calculateCurrentPrice();
                removeGame(game);
                return true;
            }
        }
    }
    return false;
}   


void Person::addGame(Game game){
    games.push_back(game);
}

void Person::removeGame(Game game){
    games.remove(game);
}

Person::Person(float budget, std::string name):
    budget(budget),
    name(name)
{}

std::ostream& operator<<(std::ostream& print,const Person& person){
    print << person.getName() << "'s budget is " << person.getBudget() << " and owns:\n";
    for (Game game : person.getGames()){
        print << game;
    }
    return print;
}