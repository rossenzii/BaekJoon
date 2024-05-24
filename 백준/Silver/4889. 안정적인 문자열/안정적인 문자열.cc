#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int main(){
    fastio;
    string str;
    int result; 
    int t=1;
    while(1) {
        cin>>str;
        if(str[0]=='-') break;
        result = 0;
        stack<char>s;
        for(int i=0; i<str.size(); i++){
            char c=str[i];
            if(c=='}' && !s.empty() && s.top() =='{') s.pop();
            else s.push(c);
        }
        while(!s.empty()) {
            char c1=s.top();
            s.pop();
            char c2=s.top();
            s.pop();
            if(c1==c2) result++;
            else result +=2;
        }
 
        cout<<t<<". "<<result <<'\n';
        t++;
    }
    return 0;
}