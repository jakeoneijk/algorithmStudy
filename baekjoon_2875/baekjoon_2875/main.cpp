//
//  main.cpp
//  baekjoon_2875
//
//  Created by Jakeone Im on 19/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int W,M,K;
    cin >> W>>M>>K;
    int team = 0;
    while(1){
        if(team <= M && team*2 <= W && (M+W - 3*team) >= K){
            team++;
        }else{
            break;
        }
    }
    team--;
    cout<<team;
    return 0;
}
