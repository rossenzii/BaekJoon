#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e18
using namespace std;

int n,m;
vector<pair<int,long long>> adj[101];
long long dist[101];
int pnode[101];

void solve(){
    for(int i=0; i<101; i++){
        dist[i]=INF;
    }
    dist[1]=0;
    for(int i=0; i<n; i++)
        for(int j=1; j<n+1; j++){
            for(auto p : adj[j]){
                if(dist[j] != INF && dist[p.first]>dist[j]+p.second){
                    dist[p.first] = dist[j] +p.second;
                    pnode[p.first] = j;
                    if(i==n-1){
                        dist[p.first] = -INF;
                    }
                }
            }
        }
    if(dist[n] == INF || dist[n] == -INF) cout<<-1; //n까지 가는 길이 없음
    else {
        int x = n;
        vector<int> v;
        while(x!=0){
            v.push_back(x);
            x=pnode[x];
        }
        for(auto i = v.rbegin(); i!=v.rend(); i++){
            cout<<*i<<' ';
        }
    }
    return;
}
int main(){
    fastio;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,-c});
    }
        solve();
        return 0;
}