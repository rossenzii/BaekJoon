#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define INF 1e9
#define MAX 501

long long d[MAX];

bool bellman_ford(int n, vector<pair<int, pair<int,int>>> &edges){
    // 모든 정점을 시작점처럼 초기화
    for(int i = 1; i <= n; i++)
        d[i] = 0;

    // n번 반복
    for(int i = 1; i <= n; i++){
        for(auto &edge : edges){
            int from = edge.first;
            int to = edge.second.first;
            int cost = edge.second.second;

            if(d[to] > d[from] + cost){
                d[to] = d[from] + cost;
                // n번째에도 갱신 발생 → 음수 사이클
                if(i == n) return true;
            }
        }
    }
    return false;
}

int main(){
    fastio;
  
    int tc;
    cin >> tc;

    while(tc--){
        int n, m, w;
        cin >> n >> m >> w;

        vector<pair<int, pair<int,int>>> edges;
        int s, e, t;

        // 도로 (양방향)
        for(int i = 0; i < m; i++){
            cin >> s >> e >> t;
            edges.push_back({s, {e, t}});
            edges.push_back({e, {s, t}});
        }

        // 웜홀 (단방향, 음수)
        for(int i = 0; i < w; i++){
            cin >> s >> e >> t;
            edges.push_back({s, {e, -t}});
        }

        if(bellman_ford(n, edges))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}