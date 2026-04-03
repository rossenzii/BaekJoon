#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int visited[2001];
int result=0;
vector<int> relation[2001];

void dfs(int cur, int cnt){
  if(cnt==5){
    result=1;
    return;
  }
  for(int i=0; i<relation[cur].size(); i++){
    if(visited[relation[cur][i]] == false){
      visited[relation[cur][i]]=true;
      dfs(relation[cur][i], cnt+1);
      visited[relation[cur][i]]=false;
    }
  }
}



int main(){
  int n, m; cin>>n>>m; // 사람의 수, 친구 관계의 수
  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b;
    relation[a].push_back(b);
    relation[b].push_back(a);
  }
  for(int i=0; i<n; i++){
    visited[i]=true;
    dfs(i,1);
    if(result==1) break;
    visited[i]=false;
  }
  cout<<result;

}