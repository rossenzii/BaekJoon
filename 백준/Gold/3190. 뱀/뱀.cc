#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};
int board[101][101];

int main(){
  cin>>n>>k;
  for(int i=0; i<k; i++){
    int a,b; cin>>a>>b;
    board[a][b]=1; // 사과 위치
  }
  cin>>l;
  vector<pair<int,char>> v;
  for(int i=0; i<l; i++){
    int a; char c; cin>>a>>c;
    v.push_back({a,c}); // 벙형 전환 정보
  }
  int x=1, y=1, d=0, time=0, idx=0;
  vector<pair<int,int>> snake; // 뱀의 몸 위치 저장
  snake.push_back({x,y});
  while(true){
    time++;
    x+=dx[d];
    y+=dy[d];
    if(x<1 || x>n || y<1 || y>n) break; // 벽에 부딪히면 종료
    for(int i=0; i<snake.size(); i++){
      if(snake[i].first==x && snake[i].second==y) { // 자기 몸에 부딪히면 종료
        cout<<time;
        return 0; 
      }
    }
    snake.push_back({x,y}); // 뱀 이동
    if(board[x][y]==1){ // 사과 먹으면 꼬리 안 줄임
      board[x][y]=0; // 사과 제거
    }
    else{ // 사과 없으면 꼬리 줄임
      snake.erase(snake.begin());
    }
    if(idx<l && time==v[idx].first){ // 방향 전환
      if(v[idx].second=='L') d=(d+3)%4; // 왼쪽으로 90도 회전
      else d=(d+1)%4; // 오른쪽으로 90도 회전
      idx++;
    }
  }
  cout<<time;
  return 0;
}