//
//  main.cpp
//  baekjoon_2309
//
//  Created by Jakeone Im on 03/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dwarp[9];
int main(int argc, const char * argv[]) {
    int sum = 0;
    for(int i  = 0; i < 9 ; i++){
        scanf("%d",&dwarp[i]);
        sum += dwarp[i];
    }
    sum -= 100;
    bool end = false;
    for(int i = 0; i < 9 ; i++){
        for(int j = i+1; j < 9;j++){
            if(dwarp[i]+dwarp[j] == sum){
                dwarp[i] = 0;
                dwarp[j] = 0;
                end = true;
                break;
            }
        }
        if(end){
            break;
        }
    }
    
    sort(dwarp,dwarp+ sizeof(dwarp)/sizeof(1));
    for(int i =2; i <9; i++){
        printf("%d\n",dwarp[i]);
    }
    
    return 0;
}
