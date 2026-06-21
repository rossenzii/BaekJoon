#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;

//🚨 거리 계산 🚨
vector<int> getDist(int start, int n){
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[start]=0;
    q.push(start);
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int next : adj[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }
    return dist;   
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    adj.resize(n+1);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // 1. 임의의 노드 1에서 가장 먼 노드 X
    vector<int> d1=getDist(1, n); // 임의의 노드
    int nodeX=1;
    for(int i=1; i<=n; i++){
        if(d1[i]>d1[nodeX]) nodeX=i;
    }
    // 2. 노드 X에서 가장 먼 노드 Y
    vector<int> dX=getDist(nodeX, n);
    int nodeY=1;
    int maxDist=0;
    for(int i=1; i<=n; i++){
        if(dX[i]>maxDist){
            maxDist=dX[i];
            nodeY=i;
        }
    }
    // 3. 판정: X로부터 거리가 maxDist인 노드가 여러 개 있는지
    int count=0;
    for(int i=1; i<=n; i++){
        if(dX[i]==maxDist) count++;
    }
    if(count>=2) return maxDist;
    
    vector<int> dY=getDist(nodeY,n);
    count=0;
    for(int i=1; i<=n; i++){
        if(dY[i]==maxDist) count++;
    }
    if(count>=2) return maxDist;
    return maxDist-1;
    
    return answer;
}