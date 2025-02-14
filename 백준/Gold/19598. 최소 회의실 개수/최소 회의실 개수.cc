#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef pair<int,int> pii;

int N, s, e, ans, cnt;
vector<pii> v;

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s>>e;
        v.push_back({s,1});
        v.push_back({e,-1});
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        cnt+=v[i].second;
        ans = max(ans, cnt);
    }
    cout<<ans<<'\n';
}