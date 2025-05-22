#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


struct step{
    int Rx, Ry;
    int Bx, By;
    int Count;
};

char mapp[11][11];
bool visited[11][11][11][11];
int N,M;
int dx[]={1,-1,0,0}; // 아래, 위, 오, 왼
int dy[]={0,0,1,-1};

void move(int& rx, int& ry, int& distance, int& i)
{
    while(mapp[rx+dx[i]][ry+dy[i]] !='#' && mapp[rx][ry] !='O')
    {
        rx+=dx[i];
        ry+=dy[i];
        distance +=1;
    }
}

void BFS(int Rx, int Ry, int Bx, int By){
    queue<step> q;
    q.push({Rx, Ry, Bx, By, 0}); //시작상태
    visited[Rx][Ry][Bx][By] = true; //방문처리
    while(!q.empty())
    {
        int rx = q.front().Rx; //현재 상태
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().Count;
        q.pop();
        
        if(count >=10 ) break;
        for(int i=0; i<4; i++)
        {
            int nrx =rx, nry = ry, nbx = bx, nby=by; //다음 위치 저장
            int rc=0, bc=0, ncount=count+1; //구슬이 이동한 칸 수
            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);
            
            if(mapp[nbx][nby]=='O') continue;
            if(mapp[nrx][nry]=='O') //들어가면
            {
                cout<< 1;
                return;
            }
            if(nrx==nbx && nry==nby) //두 구슬이 겹치면
            {
                if(rc>bc) {nrx-=dx[i]; nry-=dy[i];} //더 많이 간 애가 한 칸 뒤로
                else {
                    nbx -=dx[i];
                    nby -=dy[i];
                }
            }
            //이미 방문한 상태면 통과
            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx,nry,nbx,nby,ncount});
        }
    }
    cout<<0;
}
void Answer()
{
    cin>>N>>M;
    int Rx=0, Ry=0, Bx=0, By=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>mapp[i][j];
            if(mapp[i][j]=='R')
            {
                Rx=i; Ry=j;
            }
            else if(mapp[i][j]=='B')
            {
                Bx=i; By=j;
            }
        }
    }
    BFS(Rx, Ry, Bx, By);
}

int main(){
    fastio;
    Answer();
    return 0;
}