//
//  main.cpp
//  baekjoon_14889
//
//  Created by Jakeone Im on 13/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int N;
int board[21][21];
int people[21];
int answer;

void calculate(){
    int teamOne = 0;
    int teamTwo = 0;
    for(int i = 1; i < N+1 ; i++){
        for(int j = 1; j < N+1; j++){
            if(people[i] == people[j]){
                if(people[i] == 0){
                    teamOne += board[i][j];
                }else{
                    teamTwo += board[i][j];
                }
            }
        }
    }
    
    answer = min(answer,abs(teamTwo-teamOne));
    
}

void choosePeople(int time,int start){
    
    if(time == 0){
        calculate();
    }
    
    if(start < 1){
        return;
    }
    
    for(int i = start; i < N+1; i++){
        if (people[i] == 0){
            people[i] = 1;
            choosePeople(time-1,i+1);
            people[i] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    answer = 5000;
    scanf("%d",&N);
    for(int i = 1; i < N+1;i++){
        for(int j = 1; j < N+1;j++){
            scanf("%d",&board[i][j]);
        }
    }
    
    choosePeople(N/2, 1);
    
    cout<<answer;
    return 0;
}
