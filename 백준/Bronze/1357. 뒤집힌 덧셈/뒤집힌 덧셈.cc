#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    string a,b;
    cin>>a>>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string answ=to_string(stoi(a)+stoi(b));
    while(answ.size() && answ.back()=='0') answ.pop_back();
    reverse(answ.begin(),answ.end());
    cout<<answ<<'\n';
}