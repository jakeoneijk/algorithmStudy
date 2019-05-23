//
//  main.cpp
//  baekjoon_14499
//
//  Created by Jakeone Im on 08/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int m,n,howmanymoves;
int dice[7];
int diceVer[4] = {2,1,5,6};
int diceHori[3]= {4,1,3};
int map[22][22];
pair<int, int> diceP;

void move(int way){
    int top,topLeft,topHigh;
    int newx = diceP.first;
    int newy = diceP.second;
    
    switch (way) {
        case 1:
            newy++;
            top = diceHori[0];
            topLeft = diceVer[3];
            topHigh = diceVer[0];
            break;
        case 2:
            newy--;
            top = diceHori[2];
            topLeft = diceHori[1];
            topHigh = diceVer[0];
            break;
        case 3:
            newx--;
            top = diceVer[2];
            topLeft = diceHori[0];
            topHigh = diceVer[1];
            break;
        case 4:
            newx++;
            top = diceVer[0];
            topHigh = diceVer[3];
            topLeft = diceHori[0];
    }
    
    if(newx < 0 || newx >= m || newy < 0 || newy >= n){
        return;
    }
    
    diceVer[0] = topHigh;
    diceVer[1] = top;
    diceVer[2] = 7 - topHigh;
    diceVer[3] = 7 - top;
    diceHori[0] = topLeft;
    diceHori[1] = top;
    diceHori[2] = 7 - topLeft;
    
    if(map[newx][newy] == 0){
        map[newx][newy] = dice[diceVer[3]];
    }else{
        dice[diceVer[3]] = map[newx][newy];
        map[newx][newy] = 0;
    }
    
    diceP.first = newx;
    diceP.second = newy;
    cout<<dice[top]<<endl;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d %d %d",&m,&n,&diceP.first,&diceP.second,&howmanymoves);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n ; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i = 0; i < howmanymoves;i++){
        int x;
        scanf("%d",&x);
        move(x);
        
    }
    
    return 0;
}
