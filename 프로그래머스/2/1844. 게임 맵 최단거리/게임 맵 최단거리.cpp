#include<vector>
#include<queue>
using namespace std;

int dx[]={0,1,0,-1}; // 오, 아래, 왼, 위
int dy[]={1,0,-1,0};

void bfs(vector<vector<int>> &maps, int n, int m){
    maps[0][0]=true;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx>=0&&nx<n && ny>=0&&ny<m&&maps[nx][ny]==1){
                q.push({nx,ny});
                maps[nx][ny]=maps[x][y]+1;
            }
        }
    }
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n=maps.size();
    int m=maps[0].size();
    
    bfs(maps,n,m);
    if(maps[n-1][m-1]==1){
        return -1;
    }else{
        answer=maps[n-1][m-1];
    }
    
    return answer;
}