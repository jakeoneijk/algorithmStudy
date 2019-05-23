//
//  main.cpp
//  baekjoon_14503
//
//  Created by Jakeone Im on 10/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;

int way,N,M;
int clean = 0;
int board[50][50];
pair<int,int> position;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void changetheway(){
    way--;
    if(way < 0){
        way = way + 4;
    }
}

void solve(){
    int mx,my;
    bool nowhere = false;
    while(1){
        board[position.first][position.second] = 3;
        if(nowhere == false){
            clean++;
        }
        
        changetheway();
        mx = position.first + dx[way];
        my = position.second + dy[way];
        int turn = 0;
        nowhere = false;
        while(mx < 0 || mx > N || my < 0 || my > M || board[mx][my] != 0){
            if(turn > 2){
                nowhere = true;
                break;
            }
            changetheway();
            mx = position.first + dx[way];
            my = position.second + dy[way];
            turn++;
        }
        if(nowhere == true){
            mx = position.first - dx[way];
            my = position.second - dy[way];
            if(mx < 0 || mx > N || my < 0 || my > M || board[mx][my] == 1){
                return;
            }else{
                position.first = mx;
                position.second = my;

            }
        }else{
            position.first = mx;
            position.second = my;
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&position.first,&position.second,&way);
    for(int i =0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            scanf("%d",&board[i][j]);
        }
    }
    
    solve();
    printf("%d",clean);
    return 0;
}
