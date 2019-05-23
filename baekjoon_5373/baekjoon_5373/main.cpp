//
//  main.cpp
//  baekjoon_5373
//
//  Created by Jakeone Im on 11/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
char cube[6][3][3];
pair<int, char> cubeSide[6][4] = {{{1,'d'},{3,'l'},{4,'u'},{2,'r'}},{{5,'d'},{3,'u'},{0,'u'},{2,'u'}},{{1,'l'},{0,'l'},{4,'l'},{5,'l'}},{{1,'r'},{5,'r'},{4,'r'},{0,'r'}},{{0,'d'},{3,'d'},{5,'u'},{2,'d'}},{{4,'d'},{3,'d'},{1,'u'},{2,'d'}}};
char saven[3];


void saveLoad(bool save, int nuber, char way){
    
        switch (way) {
            case 'd':
                for(int i = 0; i < 3;i++){
                    if(save){
                        saven[i] = cube[nuber][2][i];
                    }else{
                         cube[nuber][2][i] = saven[i];
                    }
                   
                }
                break;
            case 'u':
               
                for(int i = 0; i < 3;i++){
                    if(save){
                        saven[i] = cube[nuber][0][i];
                    }else{
                        cube[nuber][0][i] = saven[i];
                    }
                    
                }
                break;
            case 'l':
                
                for(int i = 0; i < 3;i++){
                    if(save){
                        saven[i] = cube[nuber][i][0];
                    }else{
                        cube[nuber][i][0] = saven[i];
                    }
                                    }
                break;
            case 'r':
                for(int i = 0; i < 3;i++){
                    if(save){
                        saven[i] = cube[nuber][i][2];
                    }else{
                        cube[nuber][i][2] = saven[i];
                    }
                }
                break;
        }
    
}

void rotation(int index, int times){
    char temp[3];
    for(int i = 0; i < times;i++){
        saveLoad(true,cubeSide[index][0].first,cubeSide[index][i].second);
        for(int k = 0; k < 3; k++){
            temp[k] = saven[k];
        }
        saveLoad(true,cubeSide[index][3].first,cubeSide[index][i].second);
        saveLoad(false,cubeSide[index][0].first,cubeSide[index][i].second);
        saveLoad(true,cubeSide[index][2].first,cubeSide[index][i].second);
        saveLoad(false,cubeSide[index][3].first,cubeSide[index][i].second);
        saveLoad(true,cubeSide[index][1].first,cubeSide[index][i].second);
        saveLoad(false,cubeSide[index][2].first,cubeSide[index][i].second);
        
        for(int k = 0; k < 3; k++){
            saven[k] = temp[k];
        }
        
        saveLoad(false,cubeSide[index][1].first,cubeSide[index][i].second);
    }
}

void solve(char side, char way){
    int realway = (way == '+')? 1:3;
    int realSide;
    switch (side) {
        case 'U':
            realSide = 0;
            break;
        case 'D':
            realSide = 5;
            break;
        case 'F':
            realSide = 4;
            break;
        case 'B':
            realSide = 1;
            break;
        case 'L':
            realSide = 2;
            break;
        case 'R':
            realSide = 3;
            break;
    }
    
    rotation(realSide, realway);
    
    }

int main(int argc, const char * argv[]) {
    int N;
    for (int i = 0; i < 6;i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(i == 0){
                    cube[i][j][k] = 'w';
                }else if(i == 5){
                    cube[i][j][k] = 'y';
                }else if(i == 4){
                    cube[i][j][k] = 'r';
                }else if(i == 1){
                    cube[i][j][k] = 'o';
                }else if(i == 2){
                    cube[i][j][k] = 'g';
                }else if(i == 3){
                    cube[i][j][k] = 'b';
                }
            }
        }
        
    }
    
    scanf("%d",&N);
    int cases[101];
    string input[101][1000];
    for(int i = 0; i < N; i++){
        cin >> cases[i];
        for(int k =0; k < cases[i]; k++){
            cin >> input[i][k];
        }
    }
    
         for(int i = 0; i < N; i++){
        for(int k =0; k < cases[i]; k++){
            solve(input[i][k][0],input[i][k][1]);
        }
        
        for(int a = 0; a < 3; a++){
            for(int b = 0 ;b < 3; b++){
                cout<<cube[0][a][b];
            }
            cout<<endl;
        }

        
    }
    
    
    return 0;
}
