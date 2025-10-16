#include <iostream>
#define MAX 1001
#include <vector>
#include <queue>
using namespace std;

int n; int m; //노드, 간선 수
int inDegree[MAX]; //진입 차수
vector<int> graph[MAX];
queue<int> q;
int result[MAX];

void topology(){
    for(int i=1; i<=n; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
        result[i]=1; //1학기로 모두 초기화
    }
    while(!q.empty()){
        int cur=q.front(); //1을 골라
        q.pop();
        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i];
            inDegree[next]--;
            if(inDegree[next]==0){
                q.push(next);
                result[next]=max(result[next], result[cur]+1);
            }
        }
    }
}


int main(){
    int a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    topology();
    for(int i=1; i<=n; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
