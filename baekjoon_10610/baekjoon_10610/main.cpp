//
//  main.cpp
//  baekjoon_10610
//
//  Created by Jakeone Im on 20/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    char input[1000000];
    int inputInt[1000000];
    fill(inputInt, inputInt + sizeof(inputInt) / sizeof(int),-1);
    scanf("%s", input);
    int index = 0;
    char current = input[index];
    bool hasZero = false;
    int sum = 0;
    while(current != '\0'){
        if(current == '0'){
            hasZero = true;
        }
        inputInt[index] = current - '0';
        sum += current - '0';
        index++;
        current = input[index];
    }
    
    if(hasZero == true && sum % 3 == 0){
        string result="";
        sort(inputInt, inputInt + sizeof(inputInt)/sizeof(int),desc);
        index = 0;
        while(inputInt[index] != -1){
            result += std::to_string(inputInt[index]);
            index++;
        }
        cout<<result;
    }else{
        printf("%d",-1);
    }
    return 0;
}
