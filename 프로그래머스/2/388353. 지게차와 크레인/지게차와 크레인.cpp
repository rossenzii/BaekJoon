#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool isOutside(int x, int y,
               vector<string>& storage,
               vector<vector<bool>>& outside){

    for(int d=0; d<4; d++){
        int nx=x+dx[d];
        int ny=y+dy[d];

        if(outside[nx][ny])
            return true;
    }

    return false;
}

void makeOutside(vector<string>& board,
                 vector<vector<bool>>& outside){

    int n=board.size();
    int m=board[0].size();

    queue<pair<int,int>> q;

    q.push({0,0});
    outside[0][0]=true;

    while(!q.empty()){

        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int d=0; d<4; d++){

            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(outside[nx][ny])
                continue;

            if(board[nx][ny]!='.')
                continue;

            outside[nx][ny]=true;
            q.push({nx,ny});
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {

    int n=storage.size();
    int m=storage[0].size();

    vector<string> board(n+2, string(m+2,'.'));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            board[i+1][j+1]=storage[i][j];
        }
    }

    for(string req : requests){

        vector<pair<int,int>> removeList;

        vector<vector<bool>> outside(
            n+2,
            vector<bool>(m+2,false)
        );

        makeOutside(board, outside);

        char target=req[0];

        // 지게차
        if(req.size()==1){

            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){

                    if(board[i][j]!=target)
                        continue;

                    if(isOutside(i,j,board,outside))
                        removeList.push_back({i,j});
                }
            }
        }

        // 크레인
        else{

            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){

                    if(board[i][j]==target)
                        removeList.push_back({i,j});
                }
            }
        }

        for(auto pos : removeList){

            int x=pos.first;
            int y=pos.second;

            board[x][y]='.';
        }
    }

    int answer=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(board[i][j]!='.')
                answer++;
        }
    }

    return answer;
}