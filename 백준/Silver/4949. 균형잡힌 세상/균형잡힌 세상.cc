#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    for(string s; getline(cin,s) && s!=".";)
    {
        bool flag=0;
        stack <char> stck;
        for(int i=0; i<s.size();i++){
            if(s[i]=='('||s[i]=='[') stck.push(s[i]);
            else if (s[i]==')'){
                if(stck.empty()||stck.top()!='(') flag=1;
                else stck.pop();
            }
            else if(s[i]==']'){
                if(stck.empty() || stck.top()!='[') flag=1;
                else stck.pop();
            }
        }
        if(stck.size()) flag=1;
        cout<<(flag?"no":"yes")<<'\n';
        
    }
}