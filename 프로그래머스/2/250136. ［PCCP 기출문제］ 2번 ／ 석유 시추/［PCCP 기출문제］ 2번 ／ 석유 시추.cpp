#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[501][501];
map<int,int> group_size;

void grouping(int bRow, int bColumn, vector<vector<int>> &land){
    int group_id=2;
    for(int i=0; i<bRow; i++){
        for(int j=0; j<bColumn; j++){
            if(land[i][j]==1 && !visited[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                int size=0;
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    land[r][c]=group_id;
                    size++;
                    for(int d=0; d<4; d++){
                        int nr=r+dx[d];
                        int nc=c+dy[d];
                        // 범위를 벗어나지 않았다면
                        if(nr>=0 && nr<bRow && nc>=0 && nc<bColumn){
                            if(land[nr][nc]==1 && !visited[nr][nc]){
                                visited[nr][nc]=true;
                                q.push({nr,nc});
                                
                            }
                        }
                    }
                }
                group_size[group_id]=size;
                group_id++;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int n=land.size();//행
    int m=land[0].size();//열
    grouping(n,m,land);
    int max=0;
    for(int j=0; j<m; j++){
        set<int> unique_groups; // 이번 열에서 만난 덩어리 번호
        int current_oil=0;
        for(int i=0; i<n; i++){
            if(land[i][j]>1){
                unique_groups.insert(land[i][j]);
            }
        }
        for(int group_id:unique_groups){
            current_oil+=group_size[group_id];
        }
        if(current_oil>max){
            max=current_oil;
        }
    }
    
    return max;
}