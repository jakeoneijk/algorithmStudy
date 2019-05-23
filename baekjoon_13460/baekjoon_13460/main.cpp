//
//  main.cpp
//  baekjoon_13460
//
//  Created by Jakeone Im on 06/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char board[11][11];
int N,M;
pair<int,int> redball;
pair<int,int> blueball;
vector<int> success;
//0 down , 1 up , 2 left , 3 right


void move(int rx, int ry,int bx, int by, int direction){
    int mrx,mry,mbx,mby;
    mrx = rx;
    mbx = bx;
    mry = ry;
    mby = by;
    switch (direction) {
        case 0:
            while(board[mrx][mry] != '#' && board[mrx][mry] != 'O'){
                mrx++;
            }
            while(board[mbx][mby] != '#' && board[mbx][mby] != 'O'){
                mbx++;
            }
            
            if(board[mrx][mry] == '#'){
                mrx--;
            }
            
            if(board[mbx][mby] == '#'){
                mbx--;
            }
            
            if((mrx == mbx) && (mry == mby)){
                if(board[mrx][mry] != 'O'){
                    if(rx > bx){
                        mbx--;
                    }else{
                        mrx--;
                    }
                }
            }
            break;
        case 1:
            while(board[mrx][mry] != '#' && board[mrx][mry] != 'O'){
                mrx--;
            }
            while(board[mbx][mby] != '#' && board[mbx][mby] != 'O'){
                mbx--;
            }
            
            if(board[mrx][mry] == '#'){
                mrx++;
            }
            
            if(board[mbx][mby] == '#'){
                mbx++;
            }
            
            if((mrx == mbx) && (mry == mby)){
                if(board[mrx][mry] != 'O'){
                    if(rx > bx){
                        mrx++;
                    }else{
                        mbx++;
                    }
                }
            }
            break;
        case 2:
            while(board[mrx][mry] != '#' && board[mrx][mry] != 'O'){
                mry--;
            }
            while(board[mbx][mby] != '#' && board[mbx][mby] != 'O'){
                mby--;
            }
            
            if(board[mrx][mry] == '#'){
                mry++;
            }
            
            if(board[mbx][mby] == '#'){
                mby++;
            }
            
            if((mrx == mbx) && (mry == mby)){
                if(board[mrx][mry] != 'O'){
                    if(ry > by){
                        mry++;
                    }else{
                        mby++;
                    }
                }
            }
            break;
        case 3:
            while(board[mrx][mry] != '#' && board[mrx][mry] != 'O'){
                mry++;
            }
            while(board[mbx][mby] != '#' && board[mbx][mby] != 'O'){
                mby++;
            }
            
            if(board[mrx][mry] == '#'){
                mry--;
            }
            
            if(board[mbx][mby] == '#'){
                mby--;
            }
            
            if((mrx == mbx) && (mry == mby)){
                if(board[mrx][mry] != 'O'){
                    if(ry > by){
                        mby--;
                    }else{
                        mry--;
                    }
                }
            }
            break;
        default:
            break;
    }
    
    redball.first = mrx;
    redball.second = mry;
    blueball.first = mbx;
    blueball.second = mby;
}

void solve(int rx, int ry,int bx, int by, int turn){
    if(turn > 9){
        return;
    }
    for(int i = 0; i < 4;i++){
        move(rx,ry,bx,by,i);
        if(board[redball.first][redball.second] == 'O' && board[blueball.first][blueball.second] != 'O'){
            success.push_back(turn+1);
        }else{
            if(board[blueball.first][blueball.second] != 'O'){
                solve(redball.first, redball.second, blueball.first, blueball.second, turn + 1);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&M,&N);
    for(int i =0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf(" %c",&board[i][j]);
            if(board[i][j] == 'B'){
                blueball = {i,j};
            }
            if(board[i][j] == 'R'){
                redball = {i,j};
            }
        }
    }
    
    solve(redball.first, redball.second, blueball.first, blueball.second,  0);
    
    if(success.size() == 0){
        printf("%d",-1);
    }else{
        sort(success.begin(), success.end());
        printf("%d",success[0]);
    }
    return 0;
}
