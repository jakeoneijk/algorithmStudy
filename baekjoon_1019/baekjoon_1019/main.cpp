#include <iostream>
using namespace std;
int pages[10];
void calculate(int page, int gap){
    int bpage = page;
    while(bpage > 0){
        pages[bpage%10] += gap;
        bpage = bpage / 10;
    }
}
void solve(int page){
    int bookpage = page;
    int start = 1;
    int realgap = 1;
    while(bookpage >= start){
        while(((bookpage % 10) != 9) && (bookpage >= start)){
            calculate(bookpage, realgap);
            bookpage--;
        }

        if(bookpage < start){
            
            break;
        }
        while((start % 10) != 0 && bookpage >= start){
            calculate(start, realgap);
            start++;
        }
        
        start /= 10;
        bookpage /= 10;
        for(int i = 0; i < 10; i++){
            pages[i] += realgap*((bookpage-start) + 1);
        }
        realgap *= 10;
    }
}


int main(int argc, const char * argv[]) {
    
    int pag;
    scanf("%d",&pag);
    solve(pag);
    
    for(int i = 0; i < 10; i++){
        printf("%d ",pages[i]);
    }
    return 0;
}
