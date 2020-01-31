//
//  BlackJack.hpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#ifndef BlackJack_hpp
#define BlackJack_hpp

#include <stdio.h>
#include <ctime>
#include "Card.hpp"


void drawCard(vector<Card> &cardVec, vector<Card> &usedCards, int n, int &sum);
void showCard(Card card);
void showDeck(vector<Card> deck);
void showCardList(vector<Card> cards);
int showOption(vector<Card> &playerCards, vector<Card> &dealerCards);
void oneGame(Casino &casino, Player &player, int bet);
int startBlackJack(Casino &casino, Player &player, int bet);

#endif /* BlackJack_hpp */
