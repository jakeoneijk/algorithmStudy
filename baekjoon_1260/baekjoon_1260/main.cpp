//
//  main.cpp
//  baekjoon_1260
//
//  Created by Jakeone Im on 06/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int startPoint;
int numberOfPoint;
int numberOfVertex;
int graph[1001][1001];
int dfsVisited[1001];
int bfsVisited[1001];
queue<int> que;

void dfSolve(int start){
    printf("%d ",start);
    dfsVisited[start] = 1;
    for(int i = 1; i <= numberOfPoint;i++ ){
        if(dfsVisited[i] == 0 && graph[start][i] == 1){
            
            dfSolve(i);
        }
    }
        
}

void bfSolve(){
    int start;
    while(!que.empty()){
        start = que.front();
        que.pop();
        printf("%d ",start);
        
        for(int i = 1; i <= numberOfPoint;i++){
            if(bfsVisited[i] == 0 && graph[start][i] == 1){
                bfsVisited[i] = 1;
                que.push(i);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&numberOfPoint,&numberOfVertex,&startPoint);
     int x,y;
    for(int i = 0; i < numberOfVertex; i++){
        scanf("%d %d",&x,&y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    dfSolve(startPoint);
    
    printf("\n");
    bfsVisited[startPoint] = 1;
    que.push(startPoint);
    bfSolve();
    return 0;
}
