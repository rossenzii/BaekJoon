#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1001
typedef long long ll;
using namespace std;

// DFS와 BFS
int N,M,V; //정점, 간선, 시작 정점 번호
int near[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; //정점 방문 여부
queue<int> q;

void reset(){
    for(int i=1; i<=N; i++){
        visited[i]=0;
    }
}

void DFS(int v){
    visited[v] = true;
    cout<<v<<" ";
    for(int i=1; i<=N; i++){
        if(near[v][i]==1 && visited[i]==0){
            DFS(i);
        }
    }
}
void BFS(int v){
    q.push(v);
    visited[v]=true;
    cout<< v << " ";
    while(!q.empty()){
        v=q.front();
        q.pop();
        
        for(int w=1; w<=N; w++){
            if(near[v][w]==1 &&visited[w]==0){
                q.push(w);
                visited[w]=true;
                cout<<w<<" ";
            }
        }
    }
}
int main(){
    fastio;
    cin>>N>>M>>V; //정점, 간선
    for(int i=0; i<M; i++){ //간선 입력
        int a,b;
        cin>>a>>b;
        near[a][b]=1;
        near[b][a]=1;
    }
    reset();
    DFS(V);
    cout<<'\n';
    reset();
    BFS(V);
    
    return 0;
}