//
//  main.cpp
//  baekjoon_13458
//
//  Created by Jakeone Im on 07/04/2019.
//  Copyright © 2019 Jakeone Im. All rights reserved.
//

#include <iostream>
int numberOfRoom;
int room[1000001];
int oneman;
int men;
int main(int argc, const char * argv[]) {
    scanf("%d",&numberOfRoom);
    for(int i = 0; i < numberOfRoom;i++){
        scanf("%d",&room[i]);
    }
    scanf("%d %d",&oneman,&men);
    
    for(int i = 0; i < numberOfRoom; i++){
        room[i] -= oneman;
    }
    long long answer = numberOfRoom;
    for(int i = 0; i < numberOfRoom;i++){
        if(room[i] > 0){
            answer += room[i]/men;
            if(room[i]%men != 0){
                answer++;
            }
        }
    }
    
    printf("%lld",answer);
    return 0;
}
