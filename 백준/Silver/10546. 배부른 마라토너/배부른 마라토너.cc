#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int n; cin>>n;
    unordered_set<string> S;
    for(int i=1; i<2*n; i++){
        string s; cin>>s;
        if(S.count(s)) S.erase(s);
        else S.insert(s);
    }
    cout<< *S.begin() <<'\n';
    
}