//
//  BlackJack.cpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include "BlackJack.hpp"

int exist(vector<Card> usedCards, Card card){
    for(int i=0; i<usedCards.size(); i++){
        if(card.getShape() == usedCards[i].getShape()
           && card.getNumber() == usedCards[i].getNumber()){
             return 1;
        }
    }
    return 0;
}

void drawCard(vector<Card> &cardVec, vector<Card> &usedCards, int n, int &sum){
    Card card(0,0);
    for(int i=0; i<n; i++){
        int status = 1;
        while(status==1){
            int s = rand()%4;
            int x = rand()%13;
            card = Card(s, x);
            status = exist(usedCards, card);
        }
        cardVec.push_back(card);
        usedCards.push_back(card);
        sum += card.getNumber();
    }
}

void showCard(Card card){
    vector<string> picture = card.getPicture();
    for(string x : picture){
        cout<<x<<endl;;
    }
}

void showDeck(vector<Card> deck){
    for(int i=0; i<deck[1].getPicture().size(); i++){
        for(int j=0; j<deck.size(); j++){
            cout<<deck[j].getPicture()[i]<<" ";
        }
        cout<<endl;
    }

}
void showCardList(vector<Card> cards){
    for(Card card : cards){
        cout<<card.getShapeString()<<"_"<<card.getNumberChar()<<" ";
    }
}

int showOption(vector<Card> &playerCards, vector<Card> &dealerCards){
    int choice;
    int playerSum=0;
    Card back = Card();
    vector<Card> tempDealer;
    tempDealer.push_back(back);
    tempDealer.push_back(dealerCards[1]);
    for(int i=0; i<dealerCards.size()-2; i++){
        tempDealer.push_back(back);
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"dealer's second card's number is: "<<dealerCards[1].getNumber()<<endl;
    
    showDeck(tempDealer);
    cout<<endl;
    cout<<"your current deck: \n";
    showDeck(playerCards);
    cout<<endl;
    for(int i=0; i<playerCards.size(); i++){
        playerSum += playerCards[i].getNumber();
    }
    cout<<"Your curren't sum is "<<playerSum<<endl;
    cout<<"1. Draw One more Card"<<endl;
    cout<<"2. Stop"<<endl;
    cout<<"Your Choide: ";;
    cin>>choice;
    cout<<endl<<endl;
    return choice;
}

void oneGame(Casino &casino, Player &player, int bet){
    vector<Card> usedCards;
    vector<Card> dealerCards;
    vector<Card> playerCards;
    int result = 0;
    int dealerSum = 0;
    int playerSum = 0;
    
    cout<<"Dealer has drawn cards..."<<endl;
    drawCard(dealerCards, usedCards, 2, dealerSum);
    while(dealerSum<17){
        drawCard(dealerCards, usedCards, 1, dealerSum);
        cout<<"Dealer has drawn one more card..."<<endl;
    }
    cout<<"here are your cards..."<<endl;
    drawCard(playerCards, usedCards, 2, playerSum);
    
    while(dealerSum!= 21 && playerSum < 21){
        int status = showOption(playerCards, dealerCards);
        if(status == 1){
            drawCard(playerCards, usedCards, 1, playerSum);
        }
        else if(status == 2){
            result = (dealerSum < playerSum) ? bet : -bet;
            break;
        }
        else{
            cout<<"invalid option"<<endl;
        }
    }
    
    if(dealerSum == 21){
        result = -bet;
        cout<<"Dealer Black Jack.";
    }
    
    else if(playerSum == 21){
        cout<<"Player Black Jack!"<<endl;
        cout<<"You won 1.5x of the bet"<<endl;
        result = 1.5 * bet;
    }
    else if(playerSum > 21){
        result = -bet;
        cout<<"You are Busted."<<endl;
    }
    else if(dealerSum > 21){
        result = bet;
        cout<<"Dealer is Busted."<<endl;
    }

    casino.setBudget(casino.getBudget()-result);
    player.setBudget(player.getBudget()+result);
    if(result>0){
        cout<<"You won! You have $"<<player.getBudget()<<" now."<<endl;
        cout<<"Dealer's Sum is "<<dealerSum<<endl;
        cout<<"Player's Sum is "<<playerSum<<endl;
     }
    else{
        cout<<"You lost. You have $"<<player.getBudget()<<" now."<<endl;
        cout<<"Dealer's Sum is "<<dealerSum<<endl;
        cout<<"Player's Sum is "<<playerSum<<endl;
    }
    
    cout<<"Casino has $"<<casino.getBudget()<<" now."<<endl;
    cout<<"Dealer's cards were: \n";
    showDeck(dealerCards);
    cout<<"Your cards were: \n";
    showDeck(playerCards);
}


int startBlackJack(Casino &casino, Player &player, int bet){
    int status;
    oneGame(casino, player, bet);
    cout<<"1. Keep Playing"<<endl;;
    cout<<"2. Exit"<<endl;
    cin>>status;
    return status;
}





