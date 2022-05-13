#pragma once

#include<ostream>
#include <string>


class Game{
    private:
    std::string title;
    int releaseDate;
    float originalPrice;

    public:
    std::string getTitle() const { return title; }
    void setTitle(std::string &title_) { title = title_; }

    int getReleaseDate() const { return releaseDate; }
    void setReleaseDate(int releaseDate_) { releaseDate = releaseDate_; }

    float getOriginalPrice() const { return originalPrice; }
    void setOriginalPrice(float originalPrice_) { originalPrice = originalPrice_; }

    float calculateCurrentPrice()const;
    Game(std::string title, int releasedate, float originalPrice);

    friend bool operator==(const Game& game1, const Game& game2);
    friend std::ostream& operator<<(std::ostream& print,const Game& game);
    
};