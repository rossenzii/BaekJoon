#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e9


int electric(vector<vector<pair<int,int>>>& graph, int n, int a, int b){
    const int TYPE = 2;
    vector<vector<int>> dist(n + 1, vector<int>(TYPE, INF));

    // {변경 횟수, 노드, 현재 타입}
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<>
    > pq;

    // 시작점: 타입 0, 1 모두 가능
    dist[a][0] = dist[a][1] = 0;
    pq.push({0, a, 0});
    pq.push({0, a, 1});

    while(!pq.empty()){
        auto [cost, cur, prevType] = pq.top(); // cur 노드에 prevType 선로로 도착했고 그때의 변경 횟수가 cost
        /*
        pq.top()
        └─ tuple
            ├─ cost
            ├─ cur
            └─ prevType
        */
        pq.pop();

        // 이미 더 좋은 상태로 방문한 적이 있으면 스킵
        if(dist[cur][prevType] < cost) continue;

        // 현재 노드에서 나가는 간선만 탐색 (인접 리스트)
        for(auto &edge : graph[cur]){
            int next = edge.first;
            int curType = edge.second;

            // 이전 선로 타입과 다르면 변경 횟수 +1
            int nextCost = cost + (prevType != curType);

            if(dist[next][curType] > nextCost){
                dist[next][curType] = nextCost;
                pq.push({nextCost, next, curType});
            }
        }
    }

    return min(dist[b][0], dist[b][1]);
}

int main(){
    fastio;
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int s, e, t;
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
        graph[e].push_back({s, t});
    }

    int a, b;
    cin >> a >> b;

    cout << electric(graph, n, a, b);
}