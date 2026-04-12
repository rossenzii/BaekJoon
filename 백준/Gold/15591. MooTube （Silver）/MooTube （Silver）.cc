#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;

vector<pair<int, int>> usado[5001];

int bfs(int k, int v){
  int cnt=0;
  bool visited[5001]={false};
  queue<int> que;
  visited[v]=true;
  que.push(v);

  while(!que.empty()){
    int now=que.front();
    que.pop();
    for(int i=0; i<usado[now].size(); i++){
      int next = usado[now][i].second;
      int next_road = usado[now][i].first;

      if(visited[next]) continue;
      if(next_road<k) continue;

      cnt++;
      visited[next]=true;
      que.push(next);
    }
  }
  return cnt;
}


int main(){
  int n, q; cin>>n>>q;
  for(int i=0; i<n-1; i++){
    int p,q,r; cin>>p>>q>>r;
    usado[p].push_back({r,q});
    usado[q].push_back({r,p});

  }
  for(int i=0; i<q; i++){
    int k,v; cin>>k>>v;
    cout<<bfs(k,v)<<"\n";
  }
}