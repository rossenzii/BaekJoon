#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<vector<vector<int>>> Map;

bool check(int x, int y, int a){
    if(a==0){ // 기둥
        if(!y // 바닥위
           || (y-1>=0 && Map[0][x][y-1]) //다른 기둥 위
           || Map[1][x][y] //보의 오른쪽 끝 위
           || (x-1>=0 && Map[1][x-1][y])) //보의 왼쪽 끝 위
            return true;
    }
    else{
        if((y-1>=0 && Map[0][x][y-1]) // 왼쪽 끝 아래가 기둥
           || (y-1>=0 && Map[0][x+1][y-1])//오른쪽 끝 아래가 기둥
           || (x-1>=0 && Map[1][x-1][y] && Map[1][x+1][y])) //양쪽에 보가 이어짐
           return true;
    }
    return false;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    Map.assign(2, vector<vector<int>>(n+1, vector<int>(n+1)));
    int len = build_frame.size();
    int x,y,a,b;
    for(int i=0; i<len; i++){
        x = build_frame[i][0]; y = build_frame[i][1];
        a = build_frame[i][2]; b = build_frame[i][3];
        
        if(b==0){ //삭제
            Map[a][x][y]=0;
            for(int i=0; i<=n; i++){
                for(int j=0; j<=n; j++){
                    for(int k=0; k<2; k++){
                        if(Map[a][x][y] ==1) break;
                        if(Map[k][i][j]==1 && !check(i,j,k)) //
                            Map[a][x][y]=1;
                    }
                }
            }
        }
        else{
            if(check(x,y,a)) Map[a][x][y]=1;
        }
    }
    vector<vector<int>> answer;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                if(Map[k][i][j] == 1)
                    answer.push_back({i,j,k});
            }
        }
    }
    return answer;
}

