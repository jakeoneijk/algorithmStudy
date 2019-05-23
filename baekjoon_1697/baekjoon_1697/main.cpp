//
//  main.cpp
//  baekjoon_1697
//
//  Created by Jakeone Im on 08/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include "math.h"
#include <queue>

using namespace std;

int su,sis;
int visited[100002];
queue<pair<int,int>> que;
int solve(){
    que.push({0,su});
    
    while(!que.empty()){
        int turn = que.front().first;
        int position = que.front().second;
        visited[position] = 1;
        que.pop();
        if(position == sis){
            return turn;
        }
        if(position-1 == sis || position+1 == sis || 2*position == sis ){
            return turn+1;
        }
    
        if(position-1 >= 0){
            if(visited[position-1] == 0){
                visited[position-1] = 1;
                que.push({turn+1,position-1});
            }
        }
        
        if(position+1 <= sis && visited[position+1] == 0){
            visited[position+1] = 1;
            que.push({turn+1,position+1});
        }
        if(position <= sis && position*2 <= 100001){
            if(visited[position*2] == 0){
                visited[position*2] = 1;
                que.push({turn+1,2*position});
            }
            
        }
        
    }
    
    return -1;
}
int main(int argc, const char * argv[]) {
    scanf("%d %d",&su,&sis);
    printf("%d",solve());
    return 0;
}
