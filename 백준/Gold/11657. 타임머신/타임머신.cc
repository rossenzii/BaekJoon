#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 2100000000
using namespace std;

int n,m,a,b,c;
long long dist[501];
bool cycle;
vector<pair<int,int>> v[501];
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c}); //v[a]에는 여러 간선 존재!
    }
    for(int i=1; i<=n; i++){
        dist[i] = INF; //모두 INF로 세팅
    }
    dist[1] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            for(int k=0; k<v[j].size(); k++){
                int next = v[j][k].first;
                int d = v[j][k].second;
                
                if(dist[j] != INF && dist[next]>dist[j]+d)
                {
                    dist[next] = dist[j]+d;
                    if(i==n) cycle = true;
                }
            }
        }
    if(cycle) cout<<-1<<'\n';
    else{
        for(int i=2; i<=n; i++){
            cout<<(dist[i] !=INF ? dist[i]:-1) <<'\n';
        }
    }
}