//
//  main.cpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include "Game.hpp"

int main() {
    srand(time(NULL));
    start();
    char gameStart = ' ';
    cin>>gameStart;
    Player player = Player(0);
    if(gameStart == 's' || gameStart == 'S'){
        setPlayer(player);
        startGame(player);
    }
    else{
        cout<<"Wrong key, but I will start the game anyway :)"<<endl;
        setPlayer(player);
        startGame(player);
    }
}
