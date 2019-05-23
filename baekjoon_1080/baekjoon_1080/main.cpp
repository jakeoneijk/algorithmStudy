//
//  main.cpp
//  baekjoon_1080
//
//  Created by Jakeone Im on 25/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int A[50][50];
int B[50][50];

void change(int x , int y){
    for(int i = x; i < x + 3 ; i++){
        for(int j =  y; j < y + 3 ; j++){
            A[i][j] = (A[i][j] == 0)? 1 : 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d %d" , &N,&M);
    for(int i =0; i < N ; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d",&A[i][j]);
        }
    }
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            scanf("%1d", &B[i][j]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N -2; i++){
        for(int j = 0 ; j < M -2; j++){
            if(A[i][j] != B[i][j]){
                change(i, j);
                ans++;
            }
        }
        
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i][j] != B[i][j]){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
