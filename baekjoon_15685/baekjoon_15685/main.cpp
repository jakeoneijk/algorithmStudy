//
//  main.cpp
//  baekjoon_15685
//
//  Created by Jakeone Im on 11/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int board[101][101];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
vector<int> draw[20];
int number;

void dragoncurve(int startx,int starty,int way , int generation, int nd){
    for(int i = 1; i <= generation; i++){
        int size = (int)draw[nd].size();
        for(int j = size - 1; j > -1 ; j--){
            draw[nd].push_back((draw[nd][j]+1)%4);
        }
        
    }
    int size = (int)draw[nd].size();
    int x = startx;
    int y = starty;
    board[x][y] = 1;
    for(int i = 0; i < size;i++){
        x = x+dx[draw[nd][i]];
        y = y + dy[draw[nd][i]];
        if(x > -1 && x < 101 && y >-1 && y < 101){
            board[x][y] = 1;
        }
    }
}

int countf(){
    int counttt = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 &&board[i+1][j+1] == 1 ){
                counttt++;
            }
        }
    }
    
    return counttt;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&number);
    
    for(int i = 0; i < number; i++){
        int x,y,way,genera;
        scanf("%d %d %d %d",&x,&y,&way,&genera);
        draw[i].push_back(way);
        dragoncurve(y, x, way, genera, i);
    }
    int answer = countf();
    cout << answer;
    return 0;
}
