//
//  main.cpp
//  baekjoon_10972
//
//  Created by Jakeone Im on 04/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int number[10001];
void solve(int lastIndex){
    int compareIndex = lastIndex;
    int swapIndex = lastIndex - 1;
    while(compareIndex > 0){
        if(number[compareIndex] > number[swapIndex]){
            break;
        }
        swapIndex--;
        if(swapIndex < 0){
            compareIndex = compareIndex - 1;
            swapIndex = compareIndex -1;
        }
    }
    
    if(compareIndex == 0){
        printf("%d",-1);
    }else{
        int temp = number[compareIndex];
        number[compareIndex] = number[swapIndex];
        number[swapIndex] = temp;
        for(int i = 0; i < lastIndex+1; i++){
            if(i != lastIndex){
                
                printf("%d ",number[i]);
            }else{
                 printf("%d",number[i]);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int cases;
    scanf("%d",&cases);
    for(int i = 0; i < cases; i++){
        scanf("%d",&number[i]);
    }
    
    solve(cases-1);
    return 0;
}
