//
//  main.cpp
//  baekjoon_2263
//
//  Created by Jakeone Im on 31/03/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int inorder[100000];
int postorder[100000];
using namespace std;
void solve(int inorderS, int inorderE, int postorderS, int postorderE){
    
    
    if(inorderS > inorderE || postorderS > postorderE){
        return;
    }
    
    if(inorderE == inorderS){
        printf("%d ",inorder[inorderE]);
        return;
    }else if(postorderE == postorderS){
        printf("%d ",postorder[postorderE]);
        return;
    }

    
    
    printf("%d ",postorder[postorderE]);
    
    int iterator = inorderS;
    
    while(iterator <= inorderE){
        if(inorder[iterator] == postorder[postorderE]){
            break;
        }
        iterator++;
    }
    
    solve(inorderS, iterator-1, postorderS, iterator-1);
    solve(iterator+1, inorderE, postorderS+(iterator-1-inorderS), postorderE-1);
}
int main(int argc, const char * argv[]) {
    int size;
    scanf("%d",&size);
    for(int i = 0; i < size; i++){
        scanf("%d",&inorder[i]);
    }
    for(int i = 0; i < size; i++){
        scanf("%d",&postorder[i]);
    }
    solve(0, size-1, 0, size-1);
    return 0;
}
