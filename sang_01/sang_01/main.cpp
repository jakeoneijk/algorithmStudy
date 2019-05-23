//
//  main.cpp
//  sang_01
//
//  Created by Jakeone Im on 04/05/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int alphabet[200];
int ahas[200];
int bhas[200];
vector<int> onlybhas;
vector<int> onlyahas;

int main(int argc, const char * argv[]) {
    int index = 1;
    for(int i = 'a'; i < 'z'+1; i++){
        alphabet[i] = index++;
    }
    
    int a,b;
    string as,bs;
    
    cin >> a >> b;
    cin >> as >> bs;
    
    for(int i = 0 ; i < as.size(); i++){
        ahas[as[i]] = 1;
    }
    
    for(int i = 0 ; i < bs.size(); i++){
        bhas[bs[i]] = 1;
        
    }
    
    for(int i = 'a'; i < 'z'+1; i++){
        if(ahas[i] != bhas[i]){
            if(bhas[i] == 1){
                onlybhas.push_back(i);
            }else{
                onlyahas.push_back(i);
            }
        }
    }
    
    int currentdifference = 0;
    
    return 0;
    
}
