//
//  main.cpp
//  baekjoon_15684
//
//  Created by Jakeone Im on 10/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;

int board[31][11];
int test[31][31];
pair<int,int> line[3];
int numberOfLine = 4;
bool answer =false;
int H,N,M;

bool downRight(int index){
    int start = index;
    for(int i = 0; i < H; i++){
        if(test[i][start] == 1){
            start++;
        }else if(start > 0){
            if(test[i][start-1] == 1){
                start--;
            }
        }
    }
    if(start != index){
        return false;
    }else{
        return true;
    }
}

bool check(){
    for(int i = 0; i < H;i++){
        for(int j = 0; j < N;j++){
            test[i][j] = board[i][j];
        }
    }
    
    for(int i = 0; i < 3;i++){
        if(line[i].first != -1){
            test[line[i].first][line[i].second] = 1;
        }
    }
    
    for(int i = 0; i < N;i++){
        if(downRight(i) == false){
            return false;
        }
    }
    int max = 0;
    
    for(int a = 0; a < 3;a++){
        if(line[a].first != -1){
            max++;
        }
    }
    numberOfLine = min(numberOfLine,max);
    answer = true;
    return true;
}

void selectLine(int start,int turn){
    if(turn > 2){
        check();
                return;
    }
    for(int i = start; i < H*(N-1); i++){
        if(i == -1){
            selectLine(i,turn+1);
        }else{
            int x = i / (N-1);
            int y = i % (N-1);
            if(board[x][y] == 0){
                line[turn] = {x,y};
                selectLine(i+1,turn+1);
            }
        }
        
        line[turn] = {-1,-1};
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&N,&M,&H);
    for(int i = 0; i < M; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        board[x][y] = 1;
    }
    
    for(int i = 0; i < 3; i++){
        line[i] = {-1,-1};
    }
    selectLine(-1, 0);
    if(answer == true){
        cout<<numberOfLine;
    }else{
        cout<<-1;
    }
    return 0;
}
