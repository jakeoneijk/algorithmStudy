//
//  main.cpp
//  baekjoon_12100
//
//  Created by Jakeone Im on 07/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct game{
    int turn;
    int board[21][21];
};

queue<game> que;
int N;
vector<int> finalMax;

void solve(){
    while(!que.empty()){
        struct game temp = que.front();
        que.pop();
        if(temp.turn == 5){
            int max = 0;
            for( int i = 0 ; i < N ; i++){
                for(int j = 0; j < N; j++){
                    if(temp.board[i][j] > max){
                        max = temp.board[i][j];
                    }
                }
            }
            finalMax.push_back(max);
        }else{
            struct game up,down,left,right;
            up.turn = temp.turn + 1;
            down.turn = temp.turn + 1;
            left.turn = temp.turn + 1;
            right.turn = temp.turn + 1;
            int one = 0;
            int two = 0;
            int index = 0;
            for(int i = 0; i < N ; i++){
                for(int j =0; j < N; j++){
                    if(temp.board[j][i] != 0){
                        if(one == 0){
                            one = temp.board[j][i];
                        }else{
                            two = temp.board[j][i];
                            if(one == two){
                                up.board[index++][i] = one + two;
                                one = 0;
                                two = 0;
                            }else{
                                up.board[index++][i] = one;
                                one = two;
                                two = 0;
                            }
                            
                        }
                    }
                }
                
                if(one != 0){
                    up.board[index++][i] = one;
                }
                
                for(int zero = index; zero < N; zero++){
                    up.board[zero][i] = 0;
                }
                one = 0;
                index = 0;
            }
            index = N - 1;
            for(int i = 0; i < N ; i++){
                for(int j =0; j < N; j++){
                    int value = temp.board[N-1-j][i];
                    if(value != 0){
                        if(one == 0){
                            one = value;
                        }else{
                            two = value;
                            if(one == two){
                                down.board[index--][i] = one + two;
                                one = 0;
                                two = 0;
                            }else{
                                down.board[index--][i] = one;
                                one = two;
                                two = 0;
                            }
                            
                        }
                    }
                }
                
                if(one != 0){
                    down.board[index--][i] = one;
                }
                
                for(int zero = index; zero >= 0; zero--){
                    down.board[zero][i] = 0;
                }
                one = 0;
                index = N - 1;
            }
            index = 0;
            for(int i = 0; i < N ; i++){
                for(int j =0; j < N; j++){
                    if(temp.board[i][j] != 0){
                        if(one == 0){
                            one = temp.board[i][j];
                        }else{
                            two = temp.board[i][j];
                            if(one == two){
                                left.board[i][index++] = one + two;
                                one = 0;
                                two = 0;
                            }else{
                                left.board[i][index++] = one;
                                one = two;
                                two = 0;
                            }
                            
                        }
                    }
                }
                
                if(one != 0){
                    left.board[i][index++] = one;
                }
                
                for(int zero = index; zero < N; zero++){
                    left.board[i][zero] = 0;
                }
                one = 0;
                index = 0;
            }
            
            index = N - 1;
            for(int i = 0; i < N ; i++){
                for(int j =0; j < N; j++){
                    int value = temp.board[i][N-1-j];
                    if(value != 0){
                        if(one == 0){
                            one = value;
                        }else{
                            two = value;
                            if(one == two){
                                right.board[i][index--] = one + two;
                                one = 0;
                                two = 0;
                            }else{
                                right.board[i][index--] = one;
                                one = two;
                                two = 0;
                            }
                            
                        }
                    }
                }
                
                if(one != 0){
                    right.board[i][index--] = one;
                }
                
                for(int zero = index; zero >= 0; zero--){
                    right.board[i][zero] = 0;
                }
                one = 0;
                index = N - 1;
            }
            
            que.push(up);
            que.push(down);
            que.push(right);
            que.push(left);
        }
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    struct game start;
    for( int i = 0 ; i < N ; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &start.board[i][j]);
        }
    }
    
    que.push(start);
    solve();
    sort(finalMax.begin(), finalMax.end());
    printf("%d",finalMax[finalMax.size()-1]);
    return 0;
}
