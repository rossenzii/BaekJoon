#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long total_moves=0;
vector<long long> node_values;
vector<vector<int>> adj; // 트리 인접 리스트

long long dfs(int current, int parent){
    for(int next:adj[current]){
        if(next!=parent){
            node_values[current]+=dfs(next, current);
        }
    }
    long long values_to_send=node_values[current];
    total_moves+=abs(values_to_send);
    return values_to_send;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long sum=0;
    int n=a.size();
    for(int val:a) sum+=val;
    if(sum!=0) return -1;
    
    total_moves=0;
    node_values.assign(a.begin(), a.end());
    adj.assign(n, vector<int>());
    
    for(const auto&edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    dfs(0,-1);
    return total_moves;
    
}