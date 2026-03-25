#include <string>
#include <vector>
#include <stack>

using namespace std;

int pipeGraph[105][105];
int answer=0;
void makeGraph(vector<vector<int>> edge){
  int edgeSize=edge.size();
  for(int i=0; i<edgeSize; i++){ 
    int start=edge[i][0];
    int end=edge[i][1];
    int type=edge[i][2];
    pipeGraph[start][end]=type;
    pipeGraph[end][start]=type;
  }
}

vector<int> openPipe(int start, int type){
  stack<int> infectedNode; // 감염된 노드
  vector<int> result;
  bool visited[105]={false};
  infectedNode.push(start);
  visited[start]=true;
  while(!infectedNode.empty()){
    int node=infectedNode.top();
    infectedNode.pop();
    for(int i=0; i<105; i++){
      if(pipeGraph[node][i]==type&&!visited[i]){
        infectedNode.push(i);
        result.push_back(i);
        visited[i]=true;
      }
    }
  }
  return result;
}

void permutation(vector<int>& orders, int k, int infection){
  if((int)orders.size()==k){ 
    bool visited[105]={false};
    visited[infection]=true;

    for(int type:orders){
      for(int start=1; start<105; start++){
          if(visited[start]){
            vector<int> result = openPipe(start, type);
            for(int node:result){
              visited[node]=true; // 방문 처리
            }
          }
      }
    }
    int count=0;
    for(int i=1; i<105; i++){
      if(visited[i]) count++;
    }
    answer=max(answer, count);
    return;
  }
  for(int type=1; type<=3; type++){
    orders.push_back(type);
    permutation(orders, k, infection);
    orders.pop_back();
  }
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    answer = 0;
    makeGraph(edges);
    vector<int> orders;
    permutation(orders, k, infection);
    return answer;
}
