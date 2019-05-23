//
//  main.cpp
//  baekjoon_9095
//
//  Created by Jakeone Im on 04/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int solve(int n){
    if(n==0){
        return 1;
    }else if(n < 0){
        return 0;
    }
    
    return solve(n-1)+solve(n-2)+solve(n-3);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int testcase;
    scanf("%d",&testcase);
    int test;
    for(int i = 0; i < testcase; i++){
        scanf("%d",&test);
        printf("%d\n",solve(test));
    }
    return 0;
}
