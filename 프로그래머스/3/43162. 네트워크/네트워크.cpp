#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int node, int n, vector<vector<int>> &computers){
    visited[node]=true;
    for(int j=0; j<n; j++){
        if(computers[node][j] ==1 && !visited[j]){
            dfs(j,n,computers);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) { // 컴퓨터 수
    int answer = 0;
    visited.assign(n, false); 
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}