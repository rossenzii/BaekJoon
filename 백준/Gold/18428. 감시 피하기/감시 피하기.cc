#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

string board[6][6];
string origin[6][6];
bool visited[6][6];
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};
vector<pair<int,int>> teachers;
vector<pair<int,int>> students;
vector<pair<int, int>> empties;
vector<int> walls;
bool findStudent = false;

void bfs(int x, int y){
  for(int dir=0; dir<4; dir++){
    int nx=x;
    int ny=y;
    while(true){
      nx+=dx[dir];
      ny+=dy[dir];
      if(nx<0 || nx>=6 || ny<0 || ny>=6) break;
      if(board[nx][ny]=="O") break;
      if(board[nx][ny]=="S"){
        findStudent=true;
        return;
      }
    }
  }

}


void putObstacles(int n){
  for(int i=0; i<n; i++){ // 후보1
    for(int j=0; j<n; j++){
      board[i][j] = origin[i][j];
    }
  }
  for(int i=0; i<walls.size(); i++){ // 장애물 세우기
      if(walls[i]==1){
          int x = empties[i].first;
          int y = empties[i].second;
          board[x][y] = "O";
      }
  }
  findStudent = false;
  // 감시하기
  for(int i=0; i<teachers.size(); i++){
    bfs(teachers[i].first, teachers[i].second);
    if(findStudent) return;
  }
}


// 18428번
int main(){
  int n; cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>origin[i][j];
      if(origin[i][j]=="T") teachers.push_back({i,j});
      else if(origin[i][j]=="S") students.push_back({i,j});
      else if(origin[i][j]=="X") empties.push_back({i,j}); 
    }
  }
  for(int i=0; i<empties.size()-3; i++) walls.push_back(0);
  for(int i=0; i<3; i++) walls.push_back(1);
  do{
    putObstacles(n);
    if(!findStudent){
      cout<<"YES";
      return 0;
    }
  }while(next_permutation(walls.begin(), walls.end()));
  cout<<"NO";
}