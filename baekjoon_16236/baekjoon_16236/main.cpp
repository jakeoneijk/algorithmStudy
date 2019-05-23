//
//  main.cpp
//  baekjoon_16236
//
//  Created by Jakeone Im on 12/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int sizeOfShark;
pair<int, int> position;
int turn;
int N;
int board[20][20];
int visited[20][20];
queue<pair<pair<int,int>,int>> que;
vector<pair<int, int>> fish[7];
int eated[20][20];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int distance(int x, int y){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = 0;
        }
    }
    while(!que.empty()){
        que.pop();
    }
    
    que.push({position,0});
    visited[position.first][position.second]=1;
    
    int distance = -1;
    while(!que.empty()){
        int cx,cy,d;
        int mx,my;
        cx = que.front().first.first;
        cy = que.front().first.second;
        d = que.front().second;
        
        if(cx ==x && cy == y){
            distance = d;
            break;
        }
        que.pop();
        for(int i = 0; i < 4; i++){
            mx = cx+dx[i];
            my = cy+dy[i];
            if(mx > -1 && mx < N && my > -1 && my <N && visited[mx][my] == 0 && board[mx][my] <= sizeOfShark){
                visited[mx][my] = 1;
                que.push({{mx,my},d+1});
            }
        }
        
    }
    
    return distance;
}

void solve(){
    int x,y,dis;
    dis = 888;
    int levelup = 0;
    while(1){
        for(int i = 1; i < sizeOfShark&&i<7;i++){
            for(int j = 0 ; j < fish[i].size();j++){
                if(eated[fish[i][j].first][fish[i][j].second] == 0){
                    int d = distance(fish[i][j].first, fish[i][j].second);
                    if(d > 0){
                        if(d < dis){
                            x = fish[i][j].first;
                            y = fish[i][j].second;
                            dis = d;
                        }else if(d == dis){
                            if(fish[i][j].first < x){
                                x = fish[i][j].first;
                                y = fish[i][j].second;
                                dis = d;
                            }else if(fish[i][j].first == x){
                                if(y > fish[i][j].second){
                                    x = fish[i][j].first;
                                    y = fish[i][j].second;
                                    dis = d;
                                }
                            }
                        }
                    }
                }
                
            }
        }
        
        if(dis == 888){
            break;
        }else{
            levelup++;
            turn += dis;
            position.first = x;
            position.second = y;
            board[x][y] = 0;
            eated[x][y] = 1;
            if(levelup == sizeOfShark){
                levelup = 0;
                sizeOfShark++;
            }
            dis = 888;
        }

    }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    sizeOfShark = 2;
    turn = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&board[i][j]);
            if(board[i][j] == 9){
                position.first = i;
                position.second = j;
                eated[i][j] = 1;
                board[i][j] = 0;
            }else if(board[i][j] != 0){
                fish[board[i][j]].push_back({i,j});
            }
        }
    }
    
    solve();
    
    cout<<turn;
    return 0;
}
