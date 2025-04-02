#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
typedef long long ll;
using namespace std;

int N, C;
vector<int> items(30);
vector<int> lCom, rCom;

void makeCombi(vector<int>& v, int idx, int x, int end){
    if(x>C) return;
    if(idx == end){
        v.push_back(x);
        return;
    }
    makeCombi(v, idx+1, x+items[idx], end);
    makeCombi(v, idx+1, x, end);
}

int main(){
    fastio;
    cin>>N>>C;
    for(int i=0; i<N; i++) cin>>items[i];
    makeCombi(lCom, 0, 0, N/2);
    makeCombi(rCom, N/2, 0, N);
    sort(rCom.begin(), rCom.end());
    ll ans = 0;
    for(auto x: lCom){
        ans+= upper_bound(rCom.begin(), rCom.end(), C-x) - rCom.begin();
    }
    cout<<ans<<'\n';
    return 0;
}
