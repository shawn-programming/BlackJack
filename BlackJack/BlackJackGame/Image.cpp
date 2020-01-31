//
//  Image.cpp
//  BlackJack
//
//  Created by Shawn on 1/7/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include "Image.hpp"

vector<string> makeSpade(string s){
    vector<string> spade = {
    string(" _____ "),
    string("|")+s+string(" .  |"),
    string("| /.\\ |"),
    string("|(_._)|"),
    string("|  |  |"),
    string("|____")+s+string("|")
    };
    
    return spade;
}


 vector<string> makeClub(string s){
     vector<string> club = {
     string(" _____ "),
     string("|")+s+string(" _  |"),
     string("| ( ) |"),
     string("|(_._)|"),
     string("|  |  |"),
     string("|____")+s+string("|")
     };
     
     return club;
 }

vector<string> makeDiamond(string s){
    vector<string> diamond = {
    string(" _____ "),
    string("|")+s+string(" ^  |"),
    string("| / \\ |"),
    string("| \\ / |"),
    string("|  .  |"),
    string("|____")+s+string("|")
    };
    
    return diamond;
}
vector<string> makeHeart(string s){
     vector<string> heart = {
     string(" _____ "),
     string("|")+s+string("_ _ |"),
     string("|( v )|"),
     string("| \\ / |"),
     string("|  .  |"),
     string("|____")+s+string("|")
     };
     
     return heart;
 }

vector<string> makeBack(){
    vector<string> back = {
        string(" _____ "),
        string("|*****|"),
        string("|*****|"),
        string("|*****|"),
        string("|*****|"),
        string("|_____|")
    };
    
    return back;
}
