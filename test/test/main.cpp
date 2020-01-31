////
//  main.cpp
//  icpc
//
//  Created by Shawn on 1/28/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main(int argc, const char * argv[]) {
    int n;
    vector<int> numList;
    vector<int> uniList;
    
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        numList.push_back(temp);
    }
    
    sort(numList.begin(), numList.end()-1);
    
    for(int x : numList){
        for(int y : uniList){
            if( x % y != 0){
                uniList.push_back(x);
            }
        }
    }
    
    cout<< uniList.size()<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
