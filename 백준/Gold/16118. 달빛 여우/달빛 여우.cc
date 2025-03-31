#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
using namespace std;

int N,M, cnt;
vector<pair<int,int>> v[4001];
int dist[4001];
int dist2[4001][2];

void dijk(int start){
    for(int i=0; i<=N; i++) dist[i]=INF;
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now] < d) continue;
        for(auto edge:v[now]){
            int next = edge.first;
            int cost = edge.second;
            if(dist[next] > dist[now] + cost){
                dist[next] = dist[now] + cost;
                pq.push({dist[next], next});
            }
        }
    }
}
void dijk2(int start){
    for(int i=0; i<=N; i++){
        dist2[i][0]=INF;
        dist2[i][1]=INF;
    }
    dist2[start][0] = 0;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq2;
    pq2.push({0,start,0});
    while(!pq2.empty()){
        auto[time,now,state] = pq2.top();
        pq2.pop();
        if(dist2[now][state] < time) continue;
        for(auto edge : v[now]){
            int next = edge.first;
            int cost = edge.second;
            
            int nextTime;
            if(state ==0){
                nextTime = time+cost/2;
                if(dist2[next][1] > nextTime){
                    dist2[next][1] = nextTime;
                    pq2.push({nextTime, next, 1});
                }
            }else{
                nextTime = time + cost*2;
                if(dist2[next][0]>nextTime){
                    dist2[next][0]=nextTime;
                    pq2.push({nextTime, next, 0});
                }
            }
        }
        
    }
}


int main(){
    fastio;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int a, b, c; cin>>a>>b>>c;
        v[a].push_back({b,c*2});
        v[b].push_back({a,c*2});
    }
    dijk(1);
    dijk2(1);
    int answer = 0;
    for(int i=2; i<=N; i++){
        int wolfTime = min(dist2[i][0], dist2[i][1]);
        if(dist[i]<wolfTime) answer++;
    }
    cout<<answer<<"\n";
    return 0;
}