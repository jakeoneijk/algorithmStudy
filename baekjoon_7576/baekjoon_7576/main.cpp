//
//  main.cpp
//  baekjoon_7576
//
//  Created by Jakeone Im on 05/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int tomatato[1001][1001];
int day[1001][1001];
int M,N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> que;


int main(int argc, const char * argv[]) {
    scanf("%d %d",&N,&M);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&tomatato[i][j]);
            day[i][j] = -1;
            
            if(tomatato[i][j] == 1){
                que.push({i,j});
                day[i][j] =0;
            }
        }
    }
    
    while(!que.empty()){
        
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx>=0 && mx < M && my >=0 && my < N && tomatato[mx][my] == 0 && day[mx][my] == -1){
                tomatato[mx][my] = 1;
                day[mx][my] = day[x][y] + 1;
                que.push({mx,my});
            }
        }
    }
    
    int max = 0;
    bool success = true;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(day[i][j] > max){
                max = day[i][j];
            }
            if(day[i][j] == -1 && tomatato[i][j] != -1){
                success = false;
                break;
            }
        }

    }
    
    if(success){
        printf("%d",max);
    }else{
        printf("%d",-1);
    }
    
    return 0;
}
