//
//  main.cpp
//  baekjoon_1152
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int answer = 0;
    char input[1000001];
    cin.getline(input, 1000000);
    int index = 0;
    while(input[index] != '\0'){
        if(input[index] == ' '){
            answer++;
        }
        index++;
    }
    answer++;
    if(input[0]==' '){
        answer--;
    }
    if(input[index-1]==' '){
        answer--;
    }
    cout<<answer;
    return 0;
}
