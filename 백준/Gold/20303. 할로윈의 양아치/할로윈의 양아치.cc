#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, k;
vector<int> vec[30001];
bool vis[30001];
int value[30001];
vector<pair<int,int>> ans;

int dp[30001][3001];

int solve(int idx, int cnt){
    for(int i=1; i<ans.size(); i++){
        for(int j=1; j<=k; j++){
            int curCost = ans[i].second;
            int curIdx = ans[i].first;
            
            if(curIdx >j)
                dp[i][j]= dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-curIdx]+curCost, dp[i-1][j]);
        }
    }
    return dp[ans.size()-1][k-1];
}

void BFS(int start){
    queue<int> pq;
    int save = value[start];
    int cnt = 1;
    pq.push(start);
    vis[start]=true;
    while(!pq.empty()) {
        int here = pq.front();
        pq.pop();
        
        for(int i = 0; i < vec[here].size(); i++) {
            int next = vec[here][i];
            if(vis[next]) continue;
            pq.push(next);
            vis[next] = true;
            cnt++;
            save += value[next];
        }
    }
    ans.push_back({cnt, save});
}
 
int main() {
    memset(dp, 0, sizeof(dp));
    fastio;
    cin >> n >> m >> k;
 
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        value[i] = a;
    }
 
    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
 
        vec[start].push_back(end);
        vec[end].push_back(start);
    }
    ans.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        BFS(i);
    }
 
    cout << solve(0, 0);
}
