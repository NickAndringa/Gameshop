#pragma once

#include <ostream>
#include <string>
#include <list>
#include "Game.hpp"

class Person{
    private:
    float budget;
    std::string name;
    std::list<Game> games;

    public:
    bool buy(Game game);
    bool sell(Game game, Person& buyer);
    float getBudget() const { return budget; }
    void setBudget(float budget_) { budget = budget_; }
    std::list<Game> getGames() const { return games; }
    void setGames(const std::list<Game> &games_) { games = games_; }
    void addGame(Game game);
    void removeGame(Game game);
    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }
    Person(float budget, std::string name);

    friend std::ostream& operator<<(std::ostream& print,const Person& person);
    
};