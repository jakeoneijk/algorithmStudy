//
//  main.cpp
//  baekjoon_2609
//
//  Created by Jakeone Im on 02/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>

int gcd(int a, int b){
    int M , N;
    if(a > b){
        M = a;
        N = b;
    }else{
        N = a;
        M = b;
    }
    while(M%N != 0){
        int temp = M%N;
        M = N;
        N = temp;
    }
    
    return N;
}

int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d %d",&a,&b);
    int gcde = gcd(a, b);
    int mmmm = a*b / gcde;
    printf("%d\n%d",gcde,mmmm );
    return 0;
}
