#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;int main(){
    fastio;
    int n; cin>>n;
    while(n--){
        int a; cin>>a;
        multiset<int> MS;
        while(a--){
            char c; int t;
            cin>>c>>t;
            if(c=='D') {
                if(MS.empty()) continue;
                if(t==1) MS.erase(prev(MS.end()));
                else MS.erase(MS.begin());
            }
            else {MS.insert(t);}
        }
        if(MS.empty()) cout<<"EMPTY"<<'\n';
        else cout<<*prev(MS.end())<<' '<<*MS.begin()<<'\n';
    }
}
