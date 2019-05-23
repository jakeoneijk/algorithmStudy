//
//  main.cpp
//  baekjoon_11729
//
//  Created by Jakeone Im on 30/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> board[3];
int times = 0;
string answer;
void move(int from , int to , int n){
    if(n==0) return;
    move(from,6-from-to,n-1);
    answer += to_string(from)+" "+to_string(to)+"\n";
    times++;
    move(6-from-to,to,n-1);
   
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d",&N);
    move(1,3,N);
    printf("%d\n",times);
    cout<<answer;
    
    return 0;
}
