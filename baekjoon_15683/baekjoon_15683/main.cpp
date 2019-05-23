//
//  main.cpp
//  baekjoon_15683
//
//  Created by Jakeone Im on 13/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N,M;
int board[9][9];
int test[9][9];
vector<pair<pair<int, int>,pair<int,int>>> cctv;
int cctvMove[6] = {0,4,2,4,4,1};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer;

void cctvWay(int x,int y, int way){
    int mx = x+dx[way];
    int my = y+dy[way];
    while(mx > -1 && my > -1 && mx < N && my < M && test[mx][my] != 6){
        if(test[mx][my] == 0){
            test[mx][my] = -1;
        }
        mx = mx+dx[way];
        my = my+dy[way];
    }
}

void coloring(){
    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < M; j++){
            test[i][j] = board[i][j];
        }
    }
    for(int i = 0 ; i < cctv.size();i++){
        if(cctv[i].second.first == 1){
            cctvWay(cctv[i].first.first, cctv[i].first.second, cctv[i].second.second);
        }else if(cctv[i].second.first == 2){
            if(cctv[i].second.second == 0){
                cctvWay(cctv[i].first.first, cctv[i].first.second, 0);
                cctvWay(cctv[i].first.first, cctv[i].first.second, 1);
            }else{
                cctvWay(cctv[i].first.first, cctv[i].first.second, 2);
                cctvWay(cctv[i].first.first, cctv[i].first.second, 3);
            }
        }else if(cctv[i].second.first == 3){
            cctvWay(cctv[i].first.first, cctv[i].first.second, cctv[i].second.second);
            if(cctv[i].second.second < 2){
                cctvWay(cctv[i].first.first, cctv[i].first.second, cctv[i].second.second+2);
            }else{
                cctvWay(cctv[i].first.first, cctv[i].first.second, (cctv[i].second.second==2)?1:0);
            }
        }else if(cctv[i].second.first == 4){
            for(int k = 0; k < 4; k++){
                if(k != cctv[i].second.second){
                    cctvWay(cctv[i].first.first, cctv[i].first.second, k);
                }
            }
        }else if(cctv[i].second.first == 5){
            for(int k = 0; k < 4; k++){
                    cctvWay(cctv[i].first.first, cctv[i].first.second, k);
            }
        }
    }
    int where =0;
    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < M; j++){
            if(test[i][j] == 0){
                where++;
            }
        }
    }
    
    answer = min(answer,where);
    
}

void solve(int choose){
    if(choose == cctv.size()){
        coloring();
        return;
    }
    
    for(int i = 0; i<cctvMove[cctv[choose].second.first];i++){
        cctv[choose].second.second = i;
        solve(choose+1);
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&N,&M);
    answer = 500;
    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < M; j++){
            scanf("%d",&board[i][j]);
            test[i][j] = board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv.push_back({{i,j},{board[i][j],0}});
            }
        }
    }
    solve(0);
    cout<<answer;
    return 0;
}
