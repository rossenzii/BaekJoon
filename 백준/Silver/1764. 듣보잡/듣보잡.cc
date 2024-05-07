#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main(){
    fastio;
    int p,q;
    cin>>p>>q;
    set<string> S1, S2;
    for (int i=0; i<p; i++){
        string s; cin>>s;
        S1.insert(s);
    }
    for (int i=0; i<q; i++){
        string s; cin>>s;
        if(S1.count(s)) S2.insert(s);
    }
    cout<<S2.size()<<'\n';
    for(const auto&i : S2) cout<<i<<'\n';
}