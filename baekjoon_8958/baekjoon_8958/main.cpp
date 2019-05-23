//
//  main.cpp
//  baekjoon_8958
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int testcase;
    cin >> testcase;
    for(int i = 0 ; i < testcase; i++){
        string test;
        cin >> test;
        int point = 1;
        int score = 0;
        for(int j = 0 ; j < test.size(); j++){
            if(test[j]=='O'){
                score += point++;
            }else{
                point = 1;
            }
        }
        
        cout << score<<endl;
        
    }
    return 0;
}
