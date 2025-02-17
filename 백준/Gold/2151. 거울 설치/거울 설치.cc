#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 50
#define INF 987654321

using namespace std;
typedef struct{
    int x,y,Dir;
}Pos;

int N, Answer;
char MAP[MAX][MAX];
int Visit[MAX][MAX][4];
int dx[]={0,0,1,-1}; // 오,왼,위,아래
int dy[]={1,-1,0,0};
pair<int,int> Start,End; //출발, 도착 좌표
queue<Pos> Q;

void Input(){ //맵 입력받기
    int Tmp=0; // # 출구 입구 구분 용도
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>MAP[i][j];
            if(MAP[i][j] =='#'){
                if(Tmp==0){
                    Start.first=i;
                    Start.second=j;
                    Tmp++;
                }else{
                    End.first=i;
                    End.second=j;
                }
            }
            Visit[i][j][0] = Visit[i][j][1] = Visit[i][j][2] = Visit[i][j][3] = INF;
        }
    }
}

pair<int, int> Change_Direct(int Cur_Dir){
    pair<int, int> R; // 빛을 받은 거울은 2가지 방향으로 변환 가능
    if(Cur_Dir == 0 || Cur_Dir ==1){ //현재 좌 or 우로 빛 진행
        R.first =2;
        R.second =3;
    }
    else if (Cur_Dir ==2 || Cur_Dir ==3){ //현재 위 or 아래로 빛 진행
        R.first =0;
        R.second = 1;
    }
    return R;
}

void BFS(){
    while(Q.empty()==0)
    {
        int x=Q.front().x;
        int y=Q.front().y;
        int dir = Q.front().Dir;
        Q.pop();
        
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        pair<int, int> nd = Change_Direct(dir);
        
        if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
        if(MAP[nx][ny]=='*') continue;
        else if(MAP[nx][ny]=='!') //거울 설치
        {
            if(Visit[nx][ny][dir] > Visit[x][y][dir])
            {
                Visit[nx][ny][dir] = Visit[x][y][dir];
                Pos Temp;
                Temp.x=nx;
                Temp.y=ny;
                Temp.Dir = dir;
                Q.push(Temp); //새로 갱신
            }
            if(Visit[nx][ny][nd.first] > Visit[x][y][dir]+1){
                Visit[nx][ny][nd.first] = Visit[x][y][dir]+1;
                Pos Temp;
                Temp.x=nx;
                Temp.y=ny;
                Temp.Dir = nd.first;
                Q.push(Temp); //새로 갱신
            }
            if(Visit[nx][ny][nd.second] > Visit[x][y][dir]+1){
                Visit[nx][ny][nd.second] = Visit[x][y][dir]+1;
                Pos Temp;
                Temp.x=nx;
                Temp.y=ny;
                Temp.Dir = nd.second;
                Q.push(Temp);
            }
        }
        else if(MAP[nx][ny]=='.'){
            if(Visit[nx][ny][dir] > Visit[x][y][dir]){
                Visit[nx][ny][dir] = Visit[x][y][dir];
                Pos Temp;
                Temp.x=nx;
                Temp.y=ny;
                Temp.Dir = dir;
                Q.push(Temp);
            }
        }
        else if(MAP[nx][ny]=='#'){
            if(Visit[nx][ny][dir]>Visit[x][y][dir]){
                Visit[nx][ny][dir]=Visit[x][y][dir];
            }
        }
    }
}

void Solution(){
    for(int i=0; i<4; i++){
        Pos Temp;
        Temp.x=Start.first;
        Temp.y=Start.second;
        Temp.Dir = i;
        Q.push(Temp);
        Visit[Start.first][Start.second][i]=0;
    }
    BFS();
    int Answer = INF;
    for(int i=0; i<4; i++){
        if(Answer>Visit[End.first][End.second][i]){
            Answer = Visit[End.first][End.second][i];
        }
    }
    cout<<Answer<<'\n';
}


int main(){
    fastio;
    Input();
    Solution();
    return 0;
}
