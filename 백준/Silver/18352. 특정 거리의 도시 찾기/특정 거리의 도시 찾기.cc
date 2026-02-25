#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000001

vector<int> graph[MAX];
int n, m, k, x;
vector<int> dist;

vector<int> bfs(int start, int n){
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto next : graph[now]){
            if(dist[next] == MAX){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    return dist;
}

int main(){
    cin >> n >> m >> k >> x;
    dist.assign(n+1, MAX); // n 받은 후 초기화
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    bfs(x, n);
    vector<int> answer;
    for(int i=1; i<=n; i++){
        if(dist[i] == k) answer.push_back(i);
    }
    if(answer.empty()) cout << -1;
    else{
        for(int node : answer){
            cout << node << "\n";
        }
    }
}