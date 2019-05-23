//
//  main.cpp
//  baekjoon_1107
//
//  Created by Jakeone Im on 23/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int N;
int brokenButton[10];

bool possible(int channel){
    int c = channel;
    
    if(c == 0){
        if(brokenButton[c] == 0){
            return true;
        }else{
            return false;
        }
    }
    
    while(c > 0){
        if(brokenButton[c%10] == 1){
            return false;
        }
        c /= 10;
    }
    return true;
}

int solve(){
    int numberOfPushButton = 0;
    int biggerThanN = N;
    int smallerThanN = N;
    int  possiblechannel = -4;
    while(N != 100){
        if(possible(biggerThanN)){
            possiblechannel = biggerThanN;
            break;
        }
        if(possible(smallerThanN)){
            possiblechannel = smallerThanN;
            break;
        }
       
        biggerThanN--;
        smallerThanN++;
        numberOfPushButton++;
    }
    if(possiblechannel == 0){
        numberOfPushButton++;
    }else{
        while(possiblechannel > 0){
            numberOfPushButton++;
            possiblechannel /= 10;
        }
    }
    
    return min(abs(100-N),numberOfPushButton);
    
}

int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    int numberOfBrokenButton;
    scanf("%d",&numberOfBrokenButton);
    for(int i =0; i < numberOfBrokenButton; i++){
        int broke;
        scanf("%d",&broke);
        brokenButton[broke] = 1;
    }
    printf("%d",solve());
    return 0;
}
