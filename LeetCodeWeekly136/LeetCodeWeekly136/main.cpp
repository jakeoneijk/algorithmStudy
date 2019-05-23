//
//  main.cpp
//  LeetCodeWeekly136
//
//  Created by Jakeone Im on 12/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int connection[10001][10001];

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<int> result;
    

    
    result.push_back(1);
    
    for(int i = 2; i <= N; i++){
        int color = 1;
        int connection[10001];
        
        for(int k = 0; k < paths.size();k++){
            int x = paths[k][0];
            int y = paths[k][1];
            if(x == i){
                connection[y] = 1;
            }else if(y == i){
                connection[x] = 1;
            }
        }
        
        for(int j = 1; j < i; j++){
            if(connection[j] == 1){
                if(color == result[j-1]){
                    color++;
                }
            }
        }
        result.push_back(color);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> a;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    a.push_back(temp);
    temp.clear();
    
    temp.push_back(2);
    temp.push_back(3);
    a.push_back(temp);
    temp.clear();
    
    temp.push_back(3);
    temp.push_back(4);
    a.push_back(temp);
    temp.clear();
    
    temp.push_back(4);
    temp.push_back(1);
    a.push_back(temp);
    temp.clear();
    
    temp.push_back(1);
    temp.push_back(3);
    a.push_back(temp);
    temp.clear();
    
    temp.push_back(2);
    temp.push_back(4);
    a.push_back(temp);
    temp.clear();
    
    gardenNoAdj(4, a);
    return 0;
}
