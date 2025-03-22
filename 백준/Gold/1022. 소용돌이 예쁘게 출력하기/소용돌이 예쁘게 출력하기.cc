#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dx[4] = {0,-1,0,1}; // 왼 위 오 아
int dy[4] = {-1, 0, 1, 0};

int main(){
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    int board[50][5];
    for(int i=0; i<=(r2-r1); i++)
        for(int j=0; j<=(c2-c1); j++){
            board[i][j]=0; //초기화
        }
    int y=0, x=0; //중앙에서 시작
    int dir=3; //현재 방향 (처음엔 아래: dx, dy)
    int cnt=0, num=1, dcnt=1; //현재 방향으로 몇 칸 왔는지, 채워 넣을 숫자, 현재 방향으로 가야할 거리 (1->1->2->2->3->3...)
    while(!board[r2-r1][0] || !board[0][0] || !board[0][c2-c1]||!board[r2-r1][c2-c1]){
        if(y-r1>=0 && y-r1<=(r2-r1) && x-c1>=0 && x-c1<=(c2-c1)){
            board[y-r1][x-c1]=num;
        }
        cnt +=1;
        num +=1;
        y=y+dy[dir];
        x=x+dx[dir];
        if(cnt == dcnt){ // 방향을 바꾼다
            cnt = 0;
            dir = (dir+1)%4;
            if(dir==1||dir==3) // 방향이 위 or 아래일 때만 증가 (소용돌이 길이 늘리기)
                dcnt+=1; // 움직이는 칸 수 증가
        }
    }
    cnt = 0;
    while(num){
        num/=10;
        cnt+=1;
    }
    for(int i=0; i<=(r2-r1); i++){
        for(int j=0; j<=c2-c1; j++){
            cout << setw(cnt) << board[i][j] << " ";// cnt 자리로 숫자 맞춰서 출력하겠다는 뜻
        }
        cout<<'\n';
    }
    return 0;
}
