//
//  Card.cpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include "Card.hpp"

Card::Card(){
    picture = makeBack();
}
Card::Card(int shape, int number){
    this->shape = shape;

    if(number==10){
        numberChar = "J";
        this->number = 10;
    }
    else if(number==11){
        numberChar = "Q";
        this->number = 10;
    }
    else if(number == 12){
        numberChar = "K";
        this->number = 10;
    }
    else{
        this->number = number+1;
        numberChar = to_string(number+1);
    }
    
    switch (shape) {
        case 0:
            picture = makeSpade(numberChar);
            shapeString = "Spade";
            break;
            
        case 1:
            picture = makeClub(numberChar);
            shapeString = "Club";
            break;
        case 2:
            picture = makeDiamond(numberChar);
            shapeString = "Diamond";
            break;
        case 3:
            picture = makeHeart(numberChar);
            shapeString = "Heart";
            break;
    }
}

string Card::getNumberChar(){
    return numberChar;
}

string Card::getShapeString(){
    return shapeString;
}

vector<string> Card::getPicture(){
    return picture;
}

int Card::getShape(){
    return shape;
}

int Card::getNumber(){
    return number;
}

Player::Player(int budget){
    this->budget = budget;
}

int Player::getBusted(){
    return busted;
}

void Player::setBusted(){
    busted = 1;
}

int Player::getBudget(){
    return budget;
}

void Player::setBudget(int budget){
    this->budget=budget;
}


Casino::Casino(int name){
    switch(name){
        case 1:
            this->name = "Flamingo";
            bet = 10;
            casino = name;
            budget = 1000;
            break;
        case 2:
            this->name = "Mirage";
            bet = 100;
            casino = name;
            budget = 10000;
            break;
        case 3:
            this->name = "Bellagio";
            bet = 1000;
            casino = name;
            budget = 100000;
            break;
    }
}

int Casino::getBusted(){
    return busted;
}

void Casino::setBusted(){
    busted = 1;
}
int Casino::getBudget(){
    return budget;
}

int Casino::getCasino(){
    return casino;
}

int Casino::getBet(){
    return bet;
}

void Casino::setBudget(int budget){
    this->budget = budget;
}
