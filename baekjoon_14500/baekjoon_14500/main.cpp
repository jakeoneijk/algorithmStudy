//
//  main.cpp
//  baekjoon_14500
//
//  Created by Jakeone Im on 04/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int board[500][500];
int u[4];
int R,C;
int maxValue(int x, int y,int n,int oldx,int oldy){
    int answer = 0;
    int temp = 0;
    if(n==1){
        return board[x][y];
    }
    
    if(n==4){
        for(int i = 0; i < 4;i++){
            u[i] = 0;
        }
        if(x-1>-1){
            u[0] = board[x-1][y];
        }
        if(y-1>-1){
            u[1] = board[x][y-1];
        }
        
        if(x+1<R){
            u[2] = board[x+1][y];
        }
        
        if(y+1<C){
            u[3] = board[x][y+1];
        }
        int min = 1000;
        int sum = 0;
        for(int i = 0; i < 4;i++){
            sum += u[i];
            if(min > u[i]){
                min = u[i];
            }
        }
        answer = sum + board[x][y] - min;

    }
    
    if(x-1>-1 && x-1 != oldx){
        temp = board[x][y]+maxValue(x-1, y, n-1,x,y);
        answer = (answer > temp)? answer:temp;
    }
    if(y-1>-1 && y-1 != oldy){
        temp = board[x][y]+maxValue(x, y-1, n-1,x,y);
        answer = (answer > temp)? answer:temp;
    }
    if(x+1<R && x+1 != oldx){
        temp = board[x][y]+maxValue(x+1, y, n-1,x,y);
        answer = (answer > temp)? answer:temp;
    }
    
    if(y+1<C && y+1 != oldy){
        temp =board[x][y]+maxValue(x, y+1, n-1,x,y);
        answer = (answer > temp)? answer:temp;
    }
    
    
    return answer;
}
int main(int argc, const char * argv[]) {
    cout<<"ddsdsd";
    int answer = 0;
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C; j++){
            scanf("%d",&board[i][j]);
        }
    }
    int temp;
    for(int i = 0; i < R; i++){
        for(int j=0;j<C;j++){
            temp = maxValue(i, j, 4 , -1,-1);
            if(temp > answer){
                answer = temp;
            }
        }
    }
    
    printf("%d",answer);
    
    return 0;
}
