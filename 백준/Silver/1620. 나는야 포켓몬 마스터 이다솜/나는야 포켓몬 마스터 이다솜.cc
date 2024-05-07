#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main(){
    fastio;
    int a,b;
    cin>>a>>b;
    map<string, int> name_to_idx;
    map<int, string> idx_to_name;
    
    for (int i=1; i<=a; i++) {
        string str;
        cin>>str;
        name_to_idx[str]=i;
        idx_to_name[i]=str;
    }
    
    while(b--){
        string s; cin>>s;
        if(isdigit(s[0])) cout<<idx_to_name[stoi(s)]<<'\n';
            else cout<<name_to_idx[s]<<'\n';
    }
}