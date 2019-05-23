//
//  main.cpp
//  baekjoon_15486
//
//  Created by Jakeone Im on 08/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include "math.h"
using namespace std;
int day;
int dp[1500002];
pair<int,int> meetings[1500002];

int main(int argc, const char * argv[]) {
    scanf("%d",&day);
    for(int i = 1; i < day+1; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        meetings[i] = {x,y};
    }
    
    for(int i = 1; i <= day;i++){
        int temp = meetings[i].first + i-1;
        dp[i] = max(dp[i],dp[i-1]);
        dp[temp] = max(dp[i-1] + meetings[i].second , dp[temp]);
    }
    
    printf("%d",dp[day]);
    return 0;
}
