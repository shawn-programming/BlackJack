//
//  Card.hpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include "Image.hpp"

class Card{
private:
    int shape;
    int number;
    vector<string> picture;
    string numberChar;
    string shapeString;
public:
    Card(int shape, int number);
    Card();
    int getShape();
    int getNumber();
    string getNumberChar();
    string getShapeString();
    vector<string> getPicture();
};

class Player{
private:
    int budget;
    int busted;
public:
    Player(int budget);
    int getBusted();
    void setBusted();
    int getBudget();
    void setBudget(int budget);
};

class Casino{
private:
    int bet;
    int budget;
    int busted;
    int casino;
    string name;
public:
    Casino(int name);
    int getBusted();
    void setBusted();
    int getBet();
    int getBudget();
    int getCasino();
    void setBudget(int budget);
};
#endif /* Card_hpp */
