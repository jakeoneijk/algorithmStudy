//
//  main.cpp
//  baekjoon_2577
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A,B,C;
    int answer[10];
    for(int i = 0; i < sizeof(answer)/sizeof(1); i++){
        answer[i] = 0;
    }
    cin >> A >> B >> C;
    string num = to_string(A*B*C);
    for(int i = 0; i < num.size(); i++){
        answer[num[i]-'0']++;
    }
    
    for(int i = 0 ; i < sizeof(answer)/sizeof(1);i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
