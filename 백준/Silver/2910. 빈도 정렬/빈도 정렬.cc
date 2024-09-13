#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    int a,b; cin>>a>>b;
    map<int, int> cnt, order;
    vector<int> v(a);
    for(int i=0; i<a; i++){
        cin>>v[i]; cnt[v[i]]++;
        if(!order.count(v[i])) order[v[i]]=i;
    }
    
    sort(v.begin(), v.end(), [&](const int&a, const int&b)
         {
        if(cnt[a] != cnt[b]) return cnt[a]>cnt[b];
        return order[a]<order[b];
    });
    
    for (auto& i : v) cout << i << ' '; cout << '\n';
}