#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int n; cin>>n;
    priority_queue<int> PQ1; //max_heap
    priority_queue<int, vector<int>, greater<int>> PQ2; //min_heap
    while(n--){
        int t; cin>>t;
        if (PQ1.size() > PQ2.size()) PQ2.push(t); // k+1, k 일 때
        else PQ1.push(t);
        if(PQ1.size() && PQ2.size() && PQ1.top() > PQ2.top()){ 
            int t1=PQ1.top(); PQ1.pop();
            int t2=PQ2.top(); PQ2.pop();
            PQ1.push(t2); PQ2.push(t1);
        }
        cout<<PQ1.top()<<'\n';
    }
}