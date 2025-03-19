#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define max_N 800
#define max_E 2e5
using namespace std;

int N, E ,v1, v2, res=INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
vector<pair<int,int>> v[801];
int dist[801];

void dijk(int start){
    for(int i=0; i<=N; i++) dist[i] = INF;
    dist[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int d = pq.top().first; //거리
        int now = pq.top().second; //현재 위치
        pq.pop();
        if(dist[now] < d) continue;
        for(auto edge: v[now]){
            int next = edge.first;
            int cost = edge.second;
            if(dist[next]>dist[now]+cost){ // 다익스트라 갱신
                dist[next] = dist[now]+cost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main(){
    fastio;
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int v1, v2; cin>>v1>>v2;
    dijk(1);
    sToV1=dist[v1];
    sToV2=dist[v2];
    
    dijk(v1);
    V1ToV2=dist[v2];
    V1ToN=dist[N];
    
    dijk(v2);
    V2ToN=dist[N];
    
    res = min(res, sToV1+V1ToV2+V2ToN);
    res = min(res, sToV2+V1ToV2+V1ToN);
    if(V1ToV2 == INF || res == INF) cout<<-1;
    else cout<<res;
}

