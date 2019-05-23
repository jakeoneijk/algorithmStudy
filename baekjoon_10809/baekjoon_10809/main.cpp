//
//  main.cpp
//  baekjoon_10809
//
//  Created by Jakeone Im on 16/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int a['z'+1];
int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    memset(a, -1,sizeof(a));
    for(int i = 0; i < input.size(); i++){
        if(a[input[i]] == -1){
            a[input[i]] = i;
        }
        
    }
    
    for(int i = 'a'; i < 'z'+1; i++){
     
        cout<<a[i]<<" ";
    }
    return 0;
}
