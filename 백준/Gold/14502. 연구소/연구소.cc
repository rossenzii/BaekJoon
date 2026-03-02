#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int origin[8][8];
int board[8][8];
int n, m;
vector<pair<int,int>> zeros;
vector<int> walls;
bool visited[8][8];
int answer = 0;

void bfs(int x, int y){
  queue<pair<int, int>> q; // BFS를 위한 큐
  q.push(make_pair(x,y));
  visited[x][y]=true;
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(board[nx][ny]==0 && !visited[nx][ny]){ // 바이러스가 퍼질 수 있는 곳이라면
              q.push(make_pair(nx, ny));
              board[nx][ny] = 2; // 바이러스 퍼뜨리기
              visited[nx][ny] = true; 
            }
        }
    }
  }
}

void spread(){
    // board, visited 초기화
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            board[i][j] = origin[i][j];
            visited[i][j] = false;
        }

    // 벽 세우기
    for(int i=0; i<walls.size(); i++){
        if(walls[i]==1){
            int x = zeros[i].first;
            int y = zeros[i].second;
            board[x][y] = 1;
        }
    }

    // 바이러스 퍼뜨리기
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j]==2 && !visited[i][j])
                bfs(i, j);

    // 안전 구역 세기
    int result = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j]==0) result++;

    answer = max(answer, result);
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> origin[i][j];
            if(origin[i][j]==0) zeros.push_back({i,j});
        }

    for(int i=0; i<(int)zeros.size()-3; i++) walls.push_back(0);
    for(int i=0; i<3; i++) walls.push_back(1);

    do{
        spread();
    }while(next_permutation(walls.begin(), walls.end()));

    cout << answer;
    return 0;
}