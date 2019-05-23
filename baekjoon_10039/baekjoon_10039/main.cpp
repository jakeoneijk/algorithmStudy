//
//  main.cpp
//  baekjoon_10039
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int input;
    int answer = 0;
    for(int i = 0; i < 5; i++){
        cin >> input;
        if(input < 40){
            input = 40;
        }
        answer += input;
    }
    
    cout<<answer/5;
    return 0;
}
