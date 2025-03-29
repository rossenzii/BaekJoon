#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N,M,a,b;
int isDone[32001] = {0,}; //모두 0으로 초기화
vector<int> seq[32001];
priority_queue<int, vector<int>, greater<>> pq;

int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        isDone[b]++;
        seq[a].push_back(b);
    }
    for(int i=1; i<=N; i++){
        if(isDone[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int problem = pq.top();
        pq.pop();
        cout<<problem<<" ";
        for(int i=0; i<seq[problem].size(); i++){
            int next = seq[problem][i];
            isDone[next]--;
            if(isDone[next]==0){
                pq.push(next);
            }
        }
    }
    cout<<"\n";
    return 0;
}
