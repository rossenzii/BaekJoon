#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e18
using namespace std;

vector<vector<int>> node[50001]; // 연결 노드 정보
int dist[50001] = {0,}; //각 노드의 최소 intensity
bool isTop[50001] = {false,}; // 해당 노드가 산봉우리인지
vector<int> ans(2); // 정답

void dijk(vector<int> gates){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    //모든 출발지점을 큐에 넣기
    for(int i=0; i<gates.size(); i++){
        pq.push({0, gates[i]});
        dist[gates[i]] = 0;
    }
    //시작
    while(!pq.empty()){
        int x = pq.top().second; //현재 노드
        int cost = pq.top().first; // 저장된 intensity
        pq.pop();
        //ans에 값이 있고 최소 intensity가 현재 노드의 intensity보다 작을 때
        if(ans[0] != -1 && ans[1] < cost) continue;
        //해당 노드가 산봉우리일 때
        if(isTop[x]){
            if(ans[0] == -1 || ans[1]>cost){
                ans[0] = x;
                ans[1] = cost;
            }
            //intensity는 같으나 번호가 더 작은 경우 대체
            else if(ans[1] ==cost && ans[0] >x) ans[0] = x;
            continue;
        }
        //연결된 모든 노드 탐색
        for(int i=0; i<node[x].size(); i++){
            int next = node[x][i][0];
            int nCost = node[x][i][1]; //그 노드로 가는 비용
            nCost = max(nCost, cost);
            if(dist[next] ==-1 || nCost<dist[next]){ //dist 배열에 저장된 비용보다 작은 경우
                dist[next] = nCost;
                pq.push({nCost,next});
            }
        }
    }
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto it : summits) isTop[it] = true;
    for(int i=0; i<50001; i++){
        dist[i]=-1;
    }
    ans[0] = -1;
    ans[1] = -1;
    for(int i=0; i<paths.size(); i++){
        int n1 = paths[i][0];
        int n2 = paths[i][1];
        int cost = paths[i][2];
        node[n1].push_back({n2,cost});
        node[n2].push_back({n1,cost});
    }
    dijk(gates);
    return ans;
}