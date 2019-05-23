//
//  main.cpp
//  baekjoon_11724
//
//  Created by Jakeone Im on 05/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N[1001];
int groupNum;
vector<string> overs;

void insertOver(string ov,string ovReverse){
    bool insert = true;
    
    for(int i = 0; i < overs.size();i++){
        if(overs[i].compare(ov) == 0){
            insert = false;
            break;
        }
    }
    
    if(insert){
        overs.push_back(ov);
        overs.push_back(ovReverse);
    }
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    int vertexNum , testCase;
    groupNum = 0;
    scanf("%d %d",&vertexNum,&testCase);
    int a,b;
    for(int i = 0; i < testCase; i++){
        scanf("%d %d",&a,&b);
        if(N[a] != 0 || N[b] != 0){
            if(N[a] != 0 && N[b] != 0 && N[a] != N[b]){
                insertOver(to_string(N[a])+to_string(N[b]),to_string(N[b])+to_string(N[a]));
            }
            if(N[a] != 0){
                N[b] = N[a];
            }else{
                N[a] = N[b];
            }
        }else{
            groupNum++;
            N[a] = groupNum;
            N[b] = groupNum;
        }
    }
    
    printf("%d",groupNum - overs.size()/2);
    
    return 0;
}
