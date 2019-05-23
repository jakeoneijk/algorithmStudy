#include <iostream>
#include <queue>
using namespace std;
int N, M;
int board[8][8];
int test[8][8];
pair<int, int> wall[3];
int virusVisited[8][8];
queue<pair<int,int>> vi;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer;

void virus(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            virusVisited[i][j] = 0;
            test[i][j] = board[i][j];
            if(test[i][j] == 2){
                vi.push({i,j});
            }
        }
    }
    for(int i = 0 ; i < 3; i++){
        test[wall[i].first][wall[i].second] = 1;
    }
    
    while(!vi.empty()){
        int x = vi.front().first;
        int y = vi.front().second;
        vi.pop();
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            if(mx > -1 && mx < N && my > -1 && my < M && test[mx][my] != 2 && test[mx][my] != 1 && virusVisited[mx][my] == 0){
                virusVisited[mx][my] = 1;
                test[mx][my] = 2;
                vi.push({mx,my});
            }
        }
    }
    
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(test[i][j] == 0){
                max++;
            }
        }
    }
    
    answer = (answer > max)?answer:max;
}

void choosewall() {
    
    int x, y;
    for (int i = 0; i < N * M; i++) {
        x = i / M;
        y = i % M;
        if (board[x][y]!=2 && board[x][y] != 1) {
            wall[0] = { x,y };
            for (int j = i+1; j < N*M; j++) {
                x = j / M;
                y = j % M;
                if (board[x][y]!=2 && board[x][y] != 1) {
                    wall[1] = {x,y};
                    for(int k = j+1; k < N*M; k++){
                        x = k / M;
                        y = k % M;
                        if (board[x][y]!=2 && board[x][y] != 1) {
                            wall[2] = {x,y};
                            virus();
                        }
                    }
                }
            }
        }
    }
}

int main() {
    answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    choosewall();
    
    cout << answer;
    return 0;
}
