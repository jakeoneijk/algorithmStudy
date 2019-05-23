//
//  main.cpp
//  baekjoon_1201
//
//  Created by Jakeone Im on 21/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    if(m+k-1 <= n && m*k >= n){
        for (int i = 0; i < n; i++){
            a[i] = i+1;
        }
    }
    
    vector<int> g;
    g.push_back(0);
    g.push_back(k);
    n -= k;
    m -= 1;
    
    int gs = m == 0 ? 1 : n/m;
    int r = m==0? 0 : n%m;
    
    for( int i = 0; i < m; i++){
        g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
    }
    
    
    return 0;
}
