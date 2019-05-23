#include <iostream>
long long int min,max;
long long int solution[1000001];
int main(int argc, const char * argv[]) {
    scanf("%lld %lld",&min,&max);
    long long int index = 2;
    
    
    while(index*index <= max){
        long long int square = index * index;
        square = (min%square == 0)? (min / square) * square:(min / square + 1) * square;
        
        while(square <= max){
            solution[square - min] = 1;
            square += index*index;
        }
        index++;
        
    }
    
    long long int answer = 0;
    for(int i = 0; i <= max - min + 1; i++){
        if(solution[i] == 1){
            answer++;
        }
    }
    
    answer = max - min + 1 - answer;
    
    
    printf("%lld",answer);
    return 0;
}
