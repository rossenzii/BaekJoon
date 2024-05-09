#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int a,b;
    cin>>a>>b;
    unordered_map<string, string> M;
    while(a--){
        string m,n; cin>>m>>n;
        M[m]=n;
    }
    while(b--){
        string s; cin>>s;
        cout<<M[s]<<'\n';
    }
}