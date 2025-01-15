#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main(){
    fastio;
    int n,m,a; cin>>n>>m;
    vector<int> v;
    for(int i=0; i<n;i++){
        cin>>a;
        v.push_back(a); //점의 좌표
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        long long first = lower_bound(v.begin(), v.end(), a) - v.begin();
        long long second = upper_bound(v.begin(), v.end(), b) - v.begin();
        cout<<second-first<<'\n';
    }
}
