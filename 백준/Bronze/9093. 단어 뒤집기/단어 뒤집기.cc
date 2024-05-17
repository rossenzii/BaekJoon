#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int n; cin>>n;
    cin.ignore();
    stack<char> st;
    while(n--){
        string s; getline(cin, s);
        s += ' ';
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ')
            {
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }cout<<' ';
            }
            else st.push(s[i]);
        }
        cout<<'\n';
    }
}