//
//  main.cpp
//  Line01
//
//  Created by Jakeone Im on 16/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
vector<long> divisor;
vector<long> results;

void solveDivisor(long N){
    divisor.push_back(1);
    for(long i = 2; i*i <= N;i++ ){
        if(N % i == 0){
            divisor.push_back(i);
        }
    }
}

void WMinusH(long N){
    for(long i = 0 ; i < divisor.size(); i++){
        results.push_back(abs(N/divisor[i] - divisor[i]));
    }
}

int main(void) {
    long N;
    cin >> N;
    solveDivisor(N);
    WMinusH(N);
    cout<<*min_element(results.begin(), results.end())<<endl;
    return 0;
}
