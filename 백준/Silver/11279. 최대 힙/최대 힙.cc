#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main(){
    fastio;
    int n,a;
    priority_queue<int, vector<int>, less<int>> Q;
    cin>>n;
    while(n--){
        cin>>a;
        if(a==0){
            if(!Q.empty()){
                cout<<Q.top()<<'\n';
                Q.pop();
            }
            else cout<<0<<'\n';
        }
        else{
            Q.push(a);
        }
    }
    return 0;
}