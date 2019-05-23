//
//  main.cpp
//  baekjoon_1783
//
//  Created by Jakeone Im on 20/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int up, right;
    cin >> up >> right;
    int move = 1;
    up--;
    right--;
    if(up >= 2){
        if(right <= 3){
            move += right;
        }else if(right <= 5){
            move += 3;
        }else if(right >= 6){
            move += 4;
            right = right - 6;
            move += right;
        }
    }else if(up == 1){
        if(right >= 2 && right <=3){
            move++;
        }else if(right <6 && right >= 4){
            move += 2;
        }else if(right >= 6){
            move += 3;
        }
    }
    cout << move;
    return 0;
}
