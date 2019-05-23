#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int board[51][51];
int team[51][51];
int teamSum[2500];
int teamnumbers[2500];
int N,L,R,teamNumber;
int dx[2] = {0,1};
int dy[2] = {1,0};
int answer = 0;
vector<pair<int,int>> sameTeam;

void maketeam(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            team[i][j] = 0;
        }
    }
    sameTeam.clear();
    teamNumber = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 2; k++){
                int mx = i + dx[k];
                int my = j + dy[k];
                if(mx < N && my < N){
                    int differ = abs(board[i][j] - board[mx][my]);
                    if(differ >= L && differ <= R){
                        if(team[i][j] != 0 || team[mx][my] != 0){
                            if(team[i][j] != 0 && team[mx][my] != 0 && team[i][j] != team[mx][my]){
                                int minN = (team[i][j] > team[mx][my])? team[mx][my] : team[i][j];
                                int maxN = (team[i][j] < team[mx][my])? team[mx][my] : team[i][j];
                                sameTeam.push_back({minN,maxN});
                            }else{
                                int t = (team[i][j] != 0)?team[i][j]:team[mx][my];
                                team[i][j] = t;
                                team[mx][my] = t;
                            }
                        }else{
                            team[i][j] = teamNumber++;
                            team[mx][my] = team[i][j];
                        }
                    }
                }
            }

        }
    }
}

void unionStart(){
    
    for(int i = 0; i < teamNumber;i++){
        teamSum[i] = 0;
        teamnumbers[i] = 0;
    }
    for(int k = 0; k < sameTeam.size();k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(team[i][j] == sameTeam[k].second){
                    team[i][j] = sameTeam[k].first;
                }
            }
        }
    }


    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(team[i][j] != 0){
                teamSum[team[i][j]] += board[i][j];
                teamnumbers[team[i][j]]++;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(team[i][j] != 0){
                board[i][j] = teamSum[team[i][j]] / teamnumbers[team[i][j]];
            }
        }
    }
    
}

void solve(){
    while(1){
        maketeam();
        if(teamNumber == 1){
            return;
        }
        answer++;
        unionStart();
    }

}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&N,&L,&R);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&board[i][j]);
        }
    }
    solve();
    printf("%d",answer);
    return 0;
}
