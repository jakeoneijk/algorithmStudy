//
//  main.cpp
//  sang_2
//
//  Created by Jakeone Im on 04/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int pay[12][12];
int realpay[12][12];
int makerealpayv[12];
int numbersStar;
int makeV[12];

int solve(int start , int left){
    
    int answer = 50000;
    if(left == 0){
        return 0;
    }
    
    for(int i = 0; i < numbersStar; i++){
        if(makeV[i] == 0){
            int temp = realpay[start][i];
            makeV[i] = 1;
            temp += solve(i , left - 1);
            makeV[i] = 0;
            answer = min(answer,temp);
        }
    }
    
    return answer;
}

void makeRealPay(int startnumber){
    makerealpayv[startnumber] = 1;
    for(int i = 0; i < numbersStar; i++){
        realpay[startnumber][i] = pay[startnumber][i];
    }
    
    while(1){
        int minimum = 5000000;
        int minimumIndex = 0;
        bool still = false;
        
        for(int i = 0; i < numbersStar; i++){
            if(makerealpayv[i] == 0){
                if(minimum > realpay[startnumber][i]){
                    minimum = realpay[startnumber][i];
                    minimumIndex = i;
                }
               
                still = true;
            }
            
        }
        
        if(still == false){
            break;
        }
        
        makerealpayv[minimumIndex] = 1;
        
        for(int i = 0; i < numbersStar; i++){
            if(makerealpayv[i] == 0){
                int newway = realpay[startnumber][minimumIndex] + pay[minimumIndex][i];
                realpay[startnumber][i] = (newway > realpay[startnumber][i])?realpay[startnumber][i]:newway;
            }
        }

    }
    
    for(int i = 0; i < numbersStar; i++){
        makerealpayv[i] = 0;
    }
    
    
}
int main(int argc, const char * argv[]) {
    int start;
    scanf("%d %d" , &numbersStar , &start);
    for(int i = 0 ; i < numbersStar; i++){
        for(int j = 0; j < numbersStar; j++){
            scanf("%d" , &pay[i][j]);
        }
    }
    
    for(int i = 0; i < numbersStar ; i++){
        makeRealPay(i);

    }
    makeV[start] = 1;
    printf("%d",solve(start , numbersStar - 1));
        return 0;
}
