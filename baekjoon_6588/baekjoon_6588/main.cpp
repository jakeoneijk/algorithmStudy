//
//  main.cpp
//  baekjoon_6588
//
//  Created by Jakeone Im on 02/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int numbers[1000001];
vector<int> prime;

void Eratos(){
    for(int i = 2; i*i < 1000001 ; i++){
        if(numbers[i] == 0){
            for(int j = 2; j*i < 1000001; j++){
                numbers[i*j]++;
        }
        }
    }
    
    for(int i = 3; i < 1000001; i++){
        if(numbers[i] == 0){
            prime.push_back(i);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    
    int N;
    Eratos();
    scanf("%d",&N);
    while(N != 0){
        int a = 0;
        int b = 0;
        for(int i = 0; i < prime.size();i++){
            if(prime[i] >  N/2){
                break;
            }
            if(numbers[N-prime[i]]==0){
                a = prime[i];
                b = N - prime[i];
                break;
            }
        }
        
        if(a == 0 && b == 0){
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }else{
            cout<<to_string(N)+" = "+to_string(a)+" + "+to_string(b)+"\n";
        }
        scanf("%d",&N);
    }
    return 0;
}
