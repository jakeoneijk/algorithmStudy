//
//  main.cpp
//  baekjoon_1476
//
//  Created by Jakeone Im on 03/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int E,S,M;
    int ee,ss,mm;
    ee = 0;
    ss = 0;
    mm = 0;
    int year = 1;
    scanf("%d %d %d",&E,&S,&M);
    E--;
    S--;
    M--;
    while(ee != E || ss != S || mm != M){
        year++;
        ee = (ee+1)%15;
        ss = (ss+1)%28;
        mm = (mm+1)%19;
    }
    printf("%d",year);
    return 0;
}
