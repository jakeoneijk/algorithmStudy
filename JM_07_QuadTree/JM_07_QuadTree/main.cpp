//
//  main.cpp
//  JM_07_QuadTree
//
//  Created by Jakeone Im on 17/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(string in){
    cout<<in[0];
    int end = 2;
    int i = 1;
    if(in[0] == 'x'){
        while(end != 0){
            if(in[i] != 'x'){
                end--;
            }else{
                end += 3;
            }
            i++;
        }
        solve(in.substr(i+1,in.size() - i));
        solve(in.substr(1,i));
    }
    
}

int main(int argc, const char * argv[]) {
    int testCase;
    cin >> testCase;
    for(int i =0; i < testCase; i++){
        string input;
        cin >> input;
        cout<<endl;
        solve(input);
    }
    return 0;
}
