//
//  main.cpp
//  baekjoon_1062
//
//  Created by Jakeone Im on 22/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int K;
int N;
int knownAlpha['z'+1];
vector<char> needAlpha[50];
int deletedString[50];

int solve(int knownAlphaNum,char startAlpha){
    int answer = 0;
    if(K < 5){
        return 0;
    }
    
    if(K == knownAlphaNum){
        for(int i = 0; i < N; i++){
            int learned = true;
            for(int j = 0; j < needAlpha[i].size(); j++){
                if(!learned){
                    break;
                }
                if(knownAlpha[needAlpha[i][j]] == 0){
                    learned = false;
                }
            }
            
            if(learned){
                answer++;
            }
        }
        
        return answer;
    }
    
    for(int i = startAlpha; i < 'z'+1; i++){
        if(knownAlpha[i] == 0){
            knownAlpha[i] = 1;
            answer = max(solve(knownAlphaNum+1, i),answer);
            knownAlpha[i] = 0;
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&N,&K);
    knownAlpha['a'] = 1;
    knownAlpha['n'] = 1;
    knownAlpha['t'] = 1;
    knownAlpha['i'] = 1;
    knownAlpha['c'] = 1;

        for(int i = 0; i < N; i++){
            string input;
            cin >> input;
            for(int j = 4; j < input.size() - 4; j++){
                if(input[j] != 'a' && input[j] != 'n' && input[j] != 't' && input[j] != 'i' && input[j] != 'c'){
                    if(find(needAlpha[i].begin(), needAlpha[i].end(), input[j]) == needAlpha[i].end()){
                        needAlpha[i].push_back(input[j]);
                    }
                }
            }
        }
        
        printf("%d",solve(5,'b'));
   
    
    return 0;
}
