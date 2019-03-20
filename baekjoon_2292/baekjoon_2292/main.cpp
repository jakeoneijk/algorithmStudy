//
//  main.cpp
//  baekjoon_2292
//
//  Created by Jakeone Im on 17/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"start"<<endl;
    int N;
    cin >> N;
    int line = 1;
    N--;
    while(N > 0){
        N = N - 6*line;
        line++;
    }
    cout << line << endl;
    return 0;
}
