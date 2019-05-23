//
//  main.cpp
//  baekjoon_13023
//
//  Created by Jakeone Im on 06/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int friendsNumber;
int relationShipNumber;
vector<int> friendOf[2000];
bool visit[2000];

int dfs(int start,int time){
    if(time == 4){
        return true;
    }
    
    visit[start] = 1;
    
    for(int friendsOfStart: friendOf[start]){
        if(!visit[friendsOfStart]){
            if(dfs(friendsOfStart,time + 1)){
                return true;
            }
        }
    }
    visit[start] = false;
    return false;
}

bool solve(){
    for(int i = 0; i < friendsNumber;i++){
        if(dfs(i,0)){
            return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&friendsNumber,&relationShipNumber);
    for(int i = 0; i < relationShipNumber;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        friendOf[x].push_back(y);
        friendOf[y].push_back(x);
            }
    
    if(solve()){
        printf("%d",1);
    }else{
        printf("%d",0);
    }

    
    return 0;
}
