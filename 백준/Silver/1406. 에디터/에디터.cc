#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    string s; cin>>s;
    int n; cin>>n;
    cin.ignore();
    stack <char> lft;
    stack <char> rgt;
    for(int i=0; i<s.length();i++){
        lft.push(s[i]);
    }
    while(n--){
        string c;
        char a; getline(cin,c);
        if (c[0]=='L'){
            if(!lft.empty()){
                a=lft.top();
                rgt.push(a);
                lft.pop();
            }
        }
        else if (c[0]=='D'){
            if(!rgt.empty()){
                a=rgt.top();
                lft.push(a);
                rgt.pop();
            }
        }
        else if (c[0]=='B') {
            if(!lft.empty()){
                lft.pop();
            }
        }
        else if (c[0]=='P'){
            lft.push(c[2]);
        }

    }
    string ans;
    while(!lft.empty()) {ans.push_back(lft.top()); lft.pop();}
    reverse(ans.begin(), ans.end());
    while(!rgt.empty()) {ans.push_back(rgt.top()); rgt.pop();}
    cout<<ans<<'\n';
}
