#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define max 105
using namespace std;

int V,M, jh, sh;
int MAP[max][max];
int mincost = INF;
int small_time = INF;
vector<int> meet_space;
int answer=-1;

void init(){
    for(int i=0; i<max; i++){
        for(int j=0; j<max; j++){
            MAP[i][j] = INF;
        }
    }
}

void candidate(){
    for(int i=1; i<=V; i++){
        if((i==jh) || (i==sh)) continue;
        if(mincost>MAP[jh][i]+MAP[sh][i]){
            mincost=MAP[jh][i] + MAP[sh][i];
        }
    }
    for(int i=1; i<= V; i++){
        if((i==jh) || (i==sh)) continue;
        if((mincost==MAP[jh][i]+MAP[sh][i]) && (MAP[jh][i]<=MAP[sh][i]) && (small_time>MAP[jh][i])){
            //합 최소 & js <sh & jh한테 최소 시간
            small_time = MAP[jh][i];
        }
    }
    for(int i=1; i<=V; i++){
        if((i==jh)||(i==sh)){
            continue;
        }
        if((mincost==MAP[jh][i] + MAP[sh][i]) && small_time==MAP[jh][i]){
            meet_space.push_back(i);
        }
    }
    if (!meet_space.empty()) {
        sort(meet_space.begin(), meet_space.end());
        answer = meet_space[0];
    }
}

int main(){
    fastio;
    init();
    cin>>V>>M;
    for(int i=0; i<M; i++){
        int a, b, c; cin>>a>>b>>c;
        MAP[a][b] = min(MAP[a][b], c);
        MAP[b][a] = min(MAP[b][a], c);
    }
    cin>>jh>>sh;
    // 플로이드-와샬 알고리즘으로 모든 장소 간의 최단 거리를 구한다.
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (MAP[i][j] > MAP[i][k] + MAP[k][j]) {
                    MAP[i][j] = MAP[i][k] + MAP[k][j];
                }
            }
        }
    }
    candidate();
    cout<<answer<<'\n';
    return 0;
}

