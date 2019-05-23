//
//  main.cpp
//  baekjoon_1978
//
//  Created by Jakeone Im on 02/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int N;
int a[100];
bool primeNumber(int n){
    if(n==1){
        return false;
    }
    
    for(int i = 2 ; i*i <= n ; i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}
int main(int argc, const char * argv[]) {
    int answer = 0;
    scanf("%d",&N);
    for(int i = 0 ; i < N; i++){
        scanf("%d",&a[i]);
    }
    
    for(int i = 0 ; i < N; i++){
        if(primeNumber(a[i])){
            answer++;
        }
    }
    
    printf("%d",answer);
    return 0;
}
