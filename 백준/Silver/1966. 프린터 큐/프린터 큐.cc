#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main(){
    fastio;
    int N; cin>>N;
    while(N--){
        int n,a; cin>>n>>a; //n은 전체 갯수, a는 현재 위치
        vector<int> V(n);
        queue <int> Q,check;
        for(int i=0; i<n; i++){
            cin>>V[i]; //v에 중요도 저장
            Q.push(V[i]); check.push(i==a); //check에 찾으려는 수의 index에 1로 표시
        }
        sort(V.rbegin(), V.rend());
        for(int i=0; i<n; i++){
            while(Q.front()!=V[i]){
                Q.push(Q.front()); Q.pop();
                check.push(check.front()); check.pop();
            }
            if(check.front()) {cout<<i+1<<'\n'; break;}
            Q.pop(); check.pop();
        }
    }
}