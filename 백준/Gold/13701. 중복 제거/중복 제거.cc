#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
bitset<1<<25>BIT;
int main() {
    fastio;
    for(int n; cin>>n;){
        if(BIT[n]) continue;
        cout<<n<<' '; BIT[n]=1;
    }
    cout<<'\n';
}