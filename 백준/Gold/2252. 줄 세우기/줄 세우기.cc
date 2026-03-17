#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#define MAX 100010
using namespace std;

int orders[MAX]; // 해당 노드로 들어오는 간선 개수
vector<int> nodes[MAX];
int n,m; 

void topology(){
  queue<int> q;
  for(int i=1; i<=n; i++){
    if(!orders[i]) q.push(i); // 들어오는 간선이 없는 노드를 q에 저장
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    cout<<cur<<" ";
    for(int i=0; i<nodes[cur].size(); i++){
      int next = nodes[cur][i]; // 꺼낼 다음 노드
      orders[next]--; // 진입 차수 감소
      if(!orders[next]) q.push(next); // 0이면 큐에 삽입
    }
  }
  cout<<endl;
}


int main(){
  cin>>n>>m; //n명, m번 비교
  for(int i=0; i<m; i++){
    int a, b; cin>>a>>b;
    orders[b]++;
    nodes[a].push_back(b);
  }
  topology();
  
}