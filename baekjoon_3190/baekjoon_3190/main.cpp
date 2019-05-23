//
//  main.cpp
//  baekjoon_3190
//
//  Created by Jakeone Im on 07/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int boardSize;
queue<pair<int,int>> snake;
int snakeArray[102][102];
int apple[102][102];
int turn[10001]; //1 오른쪽 , -1 왼쪽
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(int argc, const char * argv[]) {
    int numberOfApple;
    int numberOfTurn;
    scanf("%d",&boardSize);
    scanf("%d",&numberOfApple);
    for(int i = 0; i < numberOfApple;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        apple[x][y] = 1;
        
    }
    scanf("%d",&numberOfTurn);
    for(int i = 0; i < numberOfTurn;i++){
        int time;
        char direction;
        cin >> time >> direction;
        turn[time] = (direction == 'D')? 1:-1;
    }
    
    int time = 0;
    int moveway = 0;
    snake.push({0,0});
    snakeArray[snake.front().first][snake.front().second] = 1;
    while(1){
        time++;
        int sx,sy;
        sx = snake.back().first + dx[moveway];
        sy = snake.back().second + dy[moveway];
        
        
        if(snakeArray[sx][sy] == 1 || sx == -1 || sx == boardSize|| sy == -1 || sy == boardSize){
            break;
        }
        
        if(!apple[sx][sy]){
            snakeArray[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }else{
            apple[sx][sy] = 0;
        }
        
        snakeArray[sx][sy] = 1;
        snake.push({sx,sy});
        
        if(turn[time] != 0){
            moveway += turn[time];
            if(moveway > 3){
                moveway -= 4;
            }else if(moveway < 0){
                moveway += 4;
            }
        }
        
        
    }
    
    printf("%d",time);
    
    return 0;
}
