#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<int>graph[50001];
int depth[50001];
int parent[50001];
bool visited[50001];
 
 
void dfs(int node, int _depth){
    visited[node] = 1;
    depth[node] = _depth;
    for(auto next: graph[node]){
        if(!visited[next]){
            parent[next] = node;    // 부모 세팅
            dfs(next, _depth + 1);
        }
    }
}
 
int lca(int a, int b){
    while(parent[a]!=parent[b]){ 
        if(depth[a] < depth[b]){ // 깊이 비교 
            b = parent[b];
        }
        else a = parent[a];
    }
    while(a!=b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}
 
int main(){
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0); // depth 저장하기
    cin>>M;
    
    
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        cout<< lca(a,b)<<'\n';
    }
}