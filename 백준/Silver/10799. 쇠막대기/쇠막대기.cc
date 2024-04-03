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
    string s;
    int ans=0;
    cin>>s;
    stack<char> st;
    for(int i=0; i<s.length();i++){
        if(s[i]=='(') {st.push(s[i]);}
        else{ // )가 들어갈때
            if(s[i-1]=='(') {
                st.pop();
                ans +=st.size();
                // )가 막대의 끝이면 ) 1개만 pop, 따라서 레이저 완성 후 남아있는 (의 개수가 곧 막대의 개수
            }
                else{ // 전 것이 )일때
                    st.pop();
                    ans++; //막대의 끝일 경우 1개만 추가
                }
        }
        
    }
    cout<<ans;
    return 0;
}
