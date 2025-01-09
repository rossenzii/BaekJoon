#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct info{
    string s;
    int d, m ,y;
    bool operator< (const info& i) const{
        if(y != i.y) return y<i.y;
        if(m != i.m) return m<i.m;
        return d<i.d;
    }
};

int main(){
    fastio;
    int n; cin>>n;
    vector <info> v(n);
    for(auto& i : v) cin>>i.s>>i.d>>i.m>>i.y;
    auto[mn, mx] = minmax_element(v.begin(), v.end());
    cout<<mx->s <<'\n' <<mn->s<<'\n';
}