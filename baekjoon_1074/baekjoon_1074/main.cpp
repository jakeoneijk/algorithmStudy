//
//  main.cpp
//  baekjoon_1074
//
//  Created by Jakeone Im on 31/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int N,r,c;
int solve(int n,int x, int y){
    if(n==2){
        if(x == r){
            if(y == c){
                return 0;
            }else{
                return 1;
            }
        }else{
            if(y == c){
                return 2;
            }else{
                return 3;
            }
        }
    }
    int answer=0;
    if(r >= x+n/2){
        if(c>=y+n/2){
            answer += (n/2 * n/2)*3;
            answer += solve(n/2, x+n/2, y+n/2);
        }else{
            answer += (n/2 * n/2)*2;
            answer += solve(n/2, x+n/2, y);
        }
    }else{
        if(c>=y+n/2){
            answer += (n/2 * n/2);
            answer += solve(n/2, x, y+n/2);
        }else{
            answer += solve(n/2, x, y);
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&N,&r,&c);
    N = 1 << N;
    printf("%d",solve(N, 0, 0));
    return 0;
}
