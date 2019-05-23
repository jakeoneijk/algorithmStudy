//
//  main.cpp
//  baekjoon_14888
//
//  Created by Jakeone Im on 13/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int maxa = -1000000000;
int mina = 1000000000;
int calNum[4];//plus,minu,mult,divi;
int number[20];
char calcu[20];
int N;

stack<pair<int,int>> st;

void calculateM(stack<pair<int,int>> stt){
    int answer = number[0];
    int index = 1;
    while(!stt.empty()){
        int ct = stt.top().first;
        int tn = stt.top().second;
        stt.pop();
        switch (ct) {
            case 0:
                for(int i = 0; i < tn;i++){
                    answer += number[index++];
                }
                break;
            case 1:
                for(int i = 0; i < tn;i++){
                    answer -= number[index++];
                }
                break;
            case 2:
                for(int i = 0; i < tn;i++){
                    answer *= number[index++];
                }
                break;
            case 3:
                for(int i = 0; i < tn;i++){
                    if(number[index] == 0){
                        return;
                    }
                    answer = answer / number[index++];
                }
                break;
            default:
                break;
        }
    }
    
    maxa = (maxa>answer)? maxa:answer;
    mina = (mina<answer)? mina:answer;
}

void chooseNumber(int preChoice){
    if(calNum[0]+calNum[1] + calNum[2] + calNum[3] == 0){
        calculateM(st);
        return;
    }
        for(int i = 0; i < 4; i++){
            if(preChoice != i){
                for(int k = 1; k <= calNum[i];k++){
                    calNum[i] -=k;
                    st.push({i,k});
                    
                    chooseNumber(i);
                    
                    calNum[i] += k;
                    st.pop();
                }
            }
            
        }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&number[i]);
    }
    scanf("%d %d %d %d",&calNum[0],&calNum[1],&calNum[2],&calNum[3]);
    
    chooseNumber(-1);
    
    cout<<maxa<<endl;
    cout<<mina<<endl;
    
    return 0;
}
