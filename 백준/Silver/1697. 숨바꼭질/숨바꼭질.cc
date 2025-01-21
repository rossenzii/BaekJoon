#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 100001
typedef long long ll;
using namespace std;

//BFS 계산
int N,K;
int visited[MAX] ={}; //정점 방문, 걸린 시간 저장

int bfs(){
    queue<int> q; //현재 위치에서 이동 가능한 다음 위치 저장
    q.push(N); //시작 위치
    visited[N]=0;
    while(!q.empty()){
        int nowPosition = q.front();
        q.pop();
        
        if(nowPosition == K) break;
        
        int minusPosition = nowPosition-1;
        int plusPosition = nowPosition+1;
        int multiPosition = nowPosition*2;
        
        if(minusPosition >=0 && visited[minusPosition] ==0){ //방문하지 않았으면
            q.push(minusPosition);
            visited[minusPosition] = visited[nowPosition] +1; //방문 시간 기록
        }
        if(plusPosition < MAX && visited[plusPosition]==0){
            q.push(plusPosition);
            visited[plusPosition] = visited[nowPosition] +1;
        }
        if(multiPosition < MAX && visited[multiPosition] ==0){
            q.push(multiPosition);
            visited[multiPosition] = visited[nowPosition] +1;
        }
    }
    return visited[K];
}

int main(){
    cin>>N>>K;
    cout<<bfs();
    return 0;
}