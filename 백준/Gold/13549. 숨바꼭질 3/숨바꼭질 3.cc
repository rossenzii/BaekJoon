#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define MAX 100000
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool visited[100001];

int main(){
  int n,c;
  int cnt=0;
  cin>>n>>c;
  pq.push({0,n});

  while(!pq.empty()){
    int time=pq.top().first; // 현재 시간
    int pos=pq.top().second; // 현재 위치
    pq.pop();
    
    visited[pos]=1;
    if(pos==c){
      cnt=time;
      break;
    }
    if(pos-1>=0&&!visited[pos-1]){
      pq.push({time+1, pos-1});
    }
    if(pos+1<=100000&&!visited[pos+1]){
      pq.push({time+1, pos+1});
    }
    if(pos*2<=100000&&!visited[pos*2]){
      pq.push({time, pos*2});
    }

  }
  cout<<cnt<<"\n";
  return 0;
}