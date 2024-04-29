#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(void){
    fastio;
    int N; cin>>N;
    while(N--){
        string a,b;
        cin>>a>>b;
        vector<int> cnt(26);
        for(int i=0; i<a.size(); i++) cnt[a[i]-'a']++;
        for(int i=0; i<b.size(); i++) cnt[b[i]-'a']--;
        bool flag =1;
        for(int i=0; i<26; i++) if(cnt[i]) flag=0;
        cout<<(flag? "Possible":"Impossible")<<'\n';
    }
    
}