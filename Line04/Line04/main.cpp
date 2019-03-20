//
//  main.cpp
//  Line04
//
//  Created by Jakeone Im on 16/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<int> heights;

int solve(int left, int right){
    int answer;
    if(left == right){
        return 0;
    }
    if((right - left) == 1){
        return 1;
    }
    
    int mid = (left + right) /2;
    
    answer = max(solve(left, mid),solve(mid+1, right));
    
    int currentLeft = mid;
    int currentRight = mid+1;
    while(1){
        
        int oldRight = currentRight;
        int maxOfRight = heights[currentRight];
        int maxRightPosition = currentRight;
        int expandRight = currentRight;
        
        int oldLeft = currentLeft;
        int maxOfLef = heights[currentLeft];
        int maxLeftPosition = currentLeft;
        int expandLeft = currentLeft;
        
        while(heights[expandRight] < heights[currentLeft] && expandRight <= right){
            if(heights[expandRight] > maxOfRight){
                maxOfRight = heights[expandRight];
                maxRightPosition = expandRight;
                
            }
            expandRight++;
        }
        if(expandRight > right){
            currentRight = maxRightPosition;
        }else{
            currentRight = expandRight;
        }
        
        while(heights[expandLeft] < heights[currentRight] && expandLeft >= left){
            if(heights[expandLeft] > maxOfLef){
                maxOfLef = heights[expandLeft];
                maxLeftPosition = expandLeft;
            }
            expandLeft--;
        }
        
        if(expandLeft < left){
            currentLeft = maxLeftPosition;
        }else{
            currentLeft = expandLeft;
        }
        
        if(oldLeft == currentLeft && oldRight == currentRight){
            break;
        }
        
        
    }
    
    
    return max(answer, currentRight-currentLeft);
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int height;
    for(int i = 0 ; i < n ; i ++){
        cin >> height;
        heights.push_back(height);
    }
    cout<<solve(0, heights.size()-1)<<endl;
    return 0;
}
