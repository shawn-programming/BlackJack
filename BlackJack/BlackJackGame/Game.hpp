//
//  Header.h
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#ifndef Game_h
#define Game_h


#include <iostream>
#include <math.h>
#include <vector>
#include "BlackJack.hpp"
using namespace std;


void setPlayer(Player &player);
void start();
int goCasino(Casino flamingo, Casino mirage, Casino bellagio, Player player);
char startGame(Player &player);



#endif /* Header_h */
