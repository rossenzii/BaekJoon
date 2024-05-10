#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    bitset<21> a;
    int n;
    cin>>n;
    while(n--){
        string s; int i;
        cin>>s;
        if(s== "add") {cin>>i; a[i]=1;}
        else if (s=="remove") {cin>>i; a[i]=0;}
        else if (s=="check") {cin>>i; cout<<a[i]<<'\n';}
        else if (s=="toggle") { cin>>i; a[i].flip();}
        else if (s=="all") {a.set();}
        else a.reset();
    }
}