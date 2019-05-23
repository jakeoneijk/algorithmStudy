//
//  main.cpp
//  baekjoon_1992
//
//  Created by Jakeone Im on 31/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;
int tree[65][65];
bool allSame(int x, int y , int range){
    int value = tree[x][y];
    for(int i = x; i < x+range; i++){
        for(int j = y; j < y+range; j++){
            if(tree[i][j] != value){
                return false;
            }
        }
    }
    return true;
    
}
string solve(int x,int y,int range){
    if(allSame(x, y, range)){
        return to_string(tree[x][y]);
    }else{
        string answer="(";
        answer += solve(x, y, range/2);
        answer += solve(x, y+range/2 , range/2);
        answer += solve(x+range/2, y, range/2);
        answer += solve(x+range/2, y+range/2, range/2);
        answer += ")";
        return answer;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int N;
    scanf("%d",&N);
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d",&tree[i][j]);
        }
    }
    cout<<solve(0, 0, N);
    return 0;
}
