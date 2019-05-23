//
//  main.cpp
//  baekjoon_1934
//
//  Created by Jakeone Im on 02/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>

int gcd(int a , int b){
    int M = (a>b)?a:b;
    int N = (a>b)?b:a;
    while(M%N != 0){
        int temp = M%N;
        M = N;
        N = temp;
    }
    
    return N;
}

int main(int argc, const char * argv[]) {
    int turn;
    int a,b;
    scanf("%d" , &turn);
    
    for(int i = 0 ; i < turn; i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",a*b/gcd(a, b));
    }
    return 0;
}
