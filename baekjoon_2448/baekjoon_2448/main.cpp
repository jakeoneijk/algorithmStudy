//
//  main.cpp
//  baekjoon_2448
//
//  Created by Jakeone Im on 15/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
string basicStar[3073] = {"  *  "," * * ","*****"};
int currentHeight = 3;
string indentation = "   ";
void makeStar(){
    while(currentHeight != N){
        for(int i  = currentHeight; i < currentHeight * 2; i++){
            basicStar[i] = basicStar[i - currentHeight]+" "+basicStar[i - currentHeight];
        }
        
        for(int i = 0; i < currentHeight; i++){
                basicStar[i]= indentation + basicStar[i] +indentation;
            
        }
        currentHeight *= 2;
        indentation = indentation + indentation;
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    makeStar();
    for(int i = 0; i < currentHeight; i++){
        cout<<basicStar[i]<<endl;
    }
    return 0;
}
