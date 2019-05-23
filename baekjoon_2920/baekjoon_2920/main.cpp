//
//  main.cpp
//  baekjoon_2920
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int oldN;
    int newN;
    
    cin >> oldN;
    bool descending = true;
    bool ascending = true;
    for(int i = 0; i < 7; i++){
        cin >>newN;
        if(newN>oldN){
            descending = false;
        }else if(oldN>newN){
            ascending = false;
        }
        
        oldN = newN;
    }
    
    if(ascending){
        cout<<"ascending";
    }else if(descending){
         cout<<"descending";
    }else{
        cout<<"mixed";
    }
    return 0;
}
