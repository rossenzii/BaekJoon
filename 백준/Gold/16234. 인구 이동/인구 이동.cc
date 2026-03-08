#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int board[51][51];
bool visited[51][51];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool bfs(int x, int y){
    queue<pair<int,int>> q;
    vector<pair<int,int>> uni;

    q.push({x,y});
    visited[x][y] = true;

    uni.push_back({x,y});
    int sum = board[x][y];

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d=0; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(visited[nx][ny]) continue;

            int diff = abs(board[cx][cy] - board[nx][ny]);

            if(diff < l || diff > r) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});

            uni.push_back({nx,ny});
            sum += board[nx][ny];
        }
    }

    if(uni.size() == 1) return false;
    int avg = sum / uni.size();

    for(auto &p : uni){
        board[p.first][p.second] = avg;
    }

    return true;
}

int main(){
    cin>>n>>l>>r;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    int days = 0;

    while(true){
        memset(visited,false,sizeof(visited));
        bool isMove = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    if(bfs(i,j)) isMove = true;
                }
            }
        }

        if(!isMove) break;
        days++;
    }

    cout << days;
}