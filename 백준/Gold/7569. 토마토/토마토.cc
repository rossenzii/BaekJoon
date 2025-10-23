#include <string>
#include <deque>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int m,n,h;
int tomato[102][102][102];
int dist[102][102][102]; // 토마토가 익는데 걸린 일 수, (z,x,y)
int cnt=0;
//(dz, dx, dy) 변화
int dz[6]={0,0,0,0,1,-1};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={1,-1,0,0,0,0};
queue<pair<pair<int,int>,int>> Q; //3차원

void inTomato(int m, int n, int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1){
                    Q.push({{i,j},k});
                    dist[i][j][k]=0;
                }
                if(tomato[i][j][k]==0){
                    dist[i][j][k]=-1; // 아직 안 익음 -> 방문 안 함
                }
            }
        }
    }
}

int main(){
    cin>>m>>n>>h;
    inTomato(m,n,h);
    while(!Q.empty()){
        pair<pair<int,int>,int> cur = Q.front();
        Q.pop();
        for(int i=0; i<6; i++){
            int nz=cur.first.first + dz[i];
            int nx=cur.first.second+dx[i];
            int ny=cur.second+dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(dist[nz][nx][ny]>=0) continue;
            dist[nz][nx][ny]=dist[cur.first.first][cur.first.second][cur.second]+1;
            Q.push({{nz,nx},ny});
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(dist[i][j][k]==-1){
                    cout<<-1;
                    return 0;
                }
                cnt=max(cnt, dist[i][j][k]);
            }
        }
    }
    cout<<cnt;
}
