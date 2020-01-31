//
//  Start.cpp
//  BlackJack
//
//  Created by Shawn on 1/6/20.
//  Copyright © 2020 Shawn. All rights reserved.
//


#include "Game.hpp"

void start(){
    string start =
    string(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n") +
    string(" @               WELCOME!               @\n") +
    string(" @                                      @\n") +
    string(" @              BLACKJACK               @\n") +
    string(" @                                      @\n") +
    string(" @         HEONJANG's First Game        @\n") +
    string(" @                                      @\n") +
    string(" @         Enter  \"S\"  to start         @\n") +
    string(" @                                      @\n") +
    string(" @               ENJOY!                 @\n") +
    string(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\n");
    cout<<start;
}

void setPlayer(Player &player){
    int playerMoney;
    cout<<endl;
    cout<<
    string("db       .d8b.  .d8888.   db    db d88888b  d888b   .d8b.  .d8888.\n")+
    string("88      d8' `8b 88'  YP   88    88 88'     88' Y8b d8' `8b 88'  YP\n")+
    string("88      88ooo88 `8bo.     Y8    8P 88ooooo 88      88ooo88 `8bo.\n")+
    string("88      88~~~88   `Y8b.   `8b  d8' 88~~~~~ 88  ooo 88~~~88   `Y8b.\n")+
    string("88booo. 88   88 db   8D    `8bd8'  88.     88. ~8~ 88   88 db   8D\n")+
    string("Y88888P YP   YP `8888Y'      YP    Y88888P  Y888P  YP   YP `8888Y'\n");
    cout<<endl;
    cout << "Welcome to Las Vegas" << endl;
    cout << "How much did you bring today? (should be less than 1000)" << endl;
    cin >> playerMoney;
    if(playerMoney>=1000){
        cout<<"You've exceeded the limit\nTrimmed your budget to 999\n";
        playerMoney = 999;
    }
    player.setBudget(playerMoney);
}
int goCasino(Casino flamingo, Casino mirage, Casino bellagio, Player player){
    int casino;
    cout << endl << "----------------------------" <<endl;
    cout << "Which Casino are you going ?" << endl;
    cout << endl;
    cout << "1. Flamingo (dealer moneny: "<<flamingo.getBudget()<<"     | betting money: 10) ";
    if(player.getBudget() < flamingo.getBet()){
        cout<<"Low Budget, Can't play here yet";
    }
    cout<<endl;
    cout << "2. Mirage   (dealer moneny: "<<mirage.getBudget()<<"    | betting money: 100) ";
    if(player.getBudget() < mirage.getBet()){
        cout<<"Low Budget, Can't play here yet";
    }
    cout<<endl;
    cout << "3. Bellagio (dealer moneny: "<<bellagio.getBudget()<<"   | betting money: 1000) ";
    if(player.getBudget() < bellagio.getBet()){
        cout<<"Low Budget, Can't play here yet";
    }
    cout<<endl;
    cout << "4. Leave this Sin City" << endl;
    cout << endl;
    cin >> casino;
    return casino;
}

char startGame(Player &player){
    int casino = 0;
    int status=1;
    Casino flamingo = Casino(1);
    Casino mirage = Casino(2);
    Casino bellagio = Casino(3);
    vector<Casino> casVec = {flamingo, mirage, bellagio};
    casino = goCasino(casVec[0], casVec[1], casVec[2], player);
    while(casino != 4){
        while(status==1){
            if(player.getBudget() < casVec[casino-1].getBet()){
                cout<<endl<<endl<<"Sorry, Sir. You don't have enough money to play in this Hotel."<<endl;
                status = 2;
            }
            else{
                status = startBlackJack(casVec[casino-1], player, casVec[casino-1].getBet());
                if(status!=2 && status!=1){
                    cout<<"Invalid Option, chose again";
                    status = 1;
                }
            }
        }
        cout<<"player money: "<<player.getBudget()<<" casino money: "<<casVec[casino-1].getBudget()<<endl;
        casino = goCasino(casVec[0], casVec[1], casVec[2], player);
        status = 1;
    }
    cout<<"Thanks for playing Heonjang's first game!\n";

    return 'E';
}
