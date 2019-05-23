//
//  main.cpp
//  LeetCodeWeeklyContest136
//
//  Created by Jakeone Im on 12/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
bool solve(string instructions){
    bool result = false;
    int way = 0;
    pair<int,int> position = {0,0};
    
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < instructions.size(); j++){
            if(instructions[j] == 'G'){
                position.first += dx[way];
                position.second += dy[way];
            }else if(instructions[j] == 'L'){
                way = (way+1)%4;
            }else{
                way = (way + 3)%4;
            }
        }
        
        if(position.first == 0 && position.second == 0){
            result = true;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    solve(input);
    return 0;
}
