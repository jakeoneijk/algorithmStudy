//
//  main.cpp
//  baekjoon_2873
//
//  Created by Jakeone Im on 27/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int ground[1000][1000];
int R,C;

string avoid(int x , int y, int xavoid , int yavoid){
    string answer = "";
    int xCurrent = x;
    int yCurrent = y;
    int turn = 0;
    while(xCurrent != x + 1 || yCurrent != C - 1){
        switch (turn) {
            case 0:
                if(xCurrent+1 == xavoid && yavoid == yCurrent){
                    turn = turn+3;
                    break;
                }
                answer += "D";
                xCurrent += 1;
                turn++;
                break;
            case 1:
            case 3:
                if(xCurrent == xavoid && yCurrent+1 == yavoid){
                    turn = (turn+3)%4;
                    break;
                }
                answer += "R";
                yCurrent += 1;
                turn = (turn + 1)%4;
                break;
            case 2:
                if(xCurrent - 1 == xavoid && yCurrent == yavoid){
                    turn = (turn+3)%4;
                    break;
                }
                answer += "U";
                xCurrent -= 1;
                turn++;
            default:
                break;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d",&ground[i][j]);
        }
    }
    string answer = "";
    if(R%2==1){
        for(int j = 0; j < R;j++){
            if(j%2 == 0){
                for(int i = 0; i < C-1;i++){
                    answer += "R";
                }
            }else{
                for(int i = 0; i < C-1;i++){
                    answer += "L";
                }
            }
            if(j != R -1){
                answer += "D";
            }
            
        }
        cout<<answer;
        return 0;
    }else if(C%2 == 1){
        for(int j = 0; j < C; j++){
            if(j % 2 == 0){
                for(int i = 0; i < R-1;i++){
                    answer += "D";
                }
            }else{
                for(int i = 0; i < R-1;i++){
                    answer += "U";
                }
            }
            
            if(j != C -1){
                answer += "R";
            }
        }
        
        cout<<answer;
        return 0;
    }
    
    int xAvoid,yAvoid;
    xAvoid = 0;
    yAvoid = 1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if((i+j) % 2 == 1){
                if(ground[xAvoid][yAvoid] > ground[i][j]){
                    xAvoid = i;
                    yAvoid = j;
                }
            }
        }
    }
    int x = 0;
    
    while (xAvoid - x > 1) {
        for(int i = 0; i < C-1;i++){
            answer += "R";
        }
        answer += "D";
        for(int i = 0; i < C-1;i++){
            answer += "L";
        }
        answer += "D";
        x +=2;
    }
    
    answer += avoid(x, 0, xAvoid, yAvoid);
    x++;
    if(x == R -1){
        cout<<answer;
    }else{
        while(x != R-1){
            answer += "D";
            for(int i = 0; i < C-1;i++){
                answer += "L";
            }
            answer += "D";
            for(int i = 0; i < C-1;i++){
                answer += "R";
            }
            x+=2;
        }
        
        cout<<answer;
        
    }
    
    return 0;
}
