#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n, m, h;
int minCnt=4;
bool edge[31][31];

bool check(){ 
  for(int i=0; i<n; i++){
    int pos=i;
    for(int j=1; j<=h; j++){
      if(edge[j][pos]) pos++; // 현재 위치에서 오른쪽 가로선 있으면 오른쪽으로 이동
      else if (pos>0 && edge[j][pos-1]) pos--; // 현재 위치에서 왼쪽에서 오는 가로선이 있으면 왼쪽으로 이동
    }
    if(pos!=i) return false; // 도착점, 출발점이 다르면 실패!
  }
  return true;
}

void dfs(int start, int cnt){
    if(check()){
      minCnt = min(minCnt, cnt);
      return;
    }
    if(cnt==3) return;
    for(int i=start; i<=h; i++){ 
      for(int j=1; j<n; j++){
        // 이미 가로선이 있으면 인접한 곳에 가로선 있으면 안됨 -> continue
        if(edge[i][j]||edge[i][j-1]||edge[i][j+1]) continue; 
        edge[i][j]=true;
        dfs(i, cnt+1);
        edge[i][j]=false;
      }
    }
}

int main(){
  cin>>n>>m>>h;
  for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    edge[a][b]=true;
  }
  dfs(1, 0);
  if(minCnt>3) cout<<-1;
  else cout<<minCnt;
  return 0;
}