//
//  main.cpp
//  baekjoon_9613
//
//  Created by Jakeone Im on 02/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int numberOfTestCase;
int testcases;
int n [101];

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

long sumGcd(){
    long answer = 0;
    for(int i = 0; i < testcases-1;i++){
        for(int j = i+1; j < testcases;j++){
            answer += gcd(n[i], n[j]);
        }
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&numberOfTestCase);
    
    for(int i = 0 ; i < numberOfTestCase;i++){
        scanf("%d",&testcases);
        for(int j = 0; j < testcases;j++){
            scanf("%d",&n[j]);
        }
        printf("%ld\n",sumGcd());
    }
    return 0;
}
